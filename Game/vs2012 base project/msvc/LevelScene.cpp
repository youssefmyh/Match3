#include "LevelScene.h"
#include <iostream>

void LevelScene::Start() {
	mEngine.Start(*this);
}

void LevelScene::init()
{
	mCommandManager = std::make_shared<CommandManager>();
	mBackground = new BackgroundItem(0, 0, 0);


}

void LevelScene::load()
{

	mlevelColors = LevelRepository::findLevelById(1);
	mMatch3Graph = std::make_shared<Match3Graph>(mlevelColors);

	int textureWidth = mEngine.GetTextureWidth(King::Engine::Texture::TEXTURE_BLUE);
	int textureHeight = mEngine.GetTextureWidth(King::Engine::Texture::TEXTURE_BLUE);
	int boardXLocation = std::get<0>(mBackground->getBoardLocation());
	int boardYLocation = std::get<1>(mBackground->getBoardLocation());

	for (uint32_t i = 0;  i< mlevelColors.size();  i++)
	{
		std::shared_ptr<JewelryItem> jItem = std::make_shared<JewelryItem>(mlevelColors[i]+1, 0, 0,textureWidth,textureHeight);
		mMatch3Graph->addNode(mlevelColors[i], i);
		jewelers.push_back(std::move(jItem));
	}

	board = new Board(0, boardXLocation , boardYLocation , mlevelColors, jewelers, textureWidth, textureHeight , mCommandManager,mMatch3Graph);

}

void LevelScene::end()
{
}

void LevelScene::won()
{
}



void LevelScene::Update() {

	mBackground->update(mEngine);
	board->update(mEngine);
	mCommandManager->update();


	std::vector<std::vector<int>> matchedNodes = mMatch3Graph->findMatchedNodes(0);

	for (size_t i = 0; i < matchedNodes.size(); i++)
	{
		removeMatchedNodes(matchedNodes[i]);
		nodesGravityCheck(matchedNodes[i]);
		fillTopVector();
	}

	

	if (mEngine.GetMouseButtonDown()) {

	//	mewelryItem->move(mEngine.GetMouseX(), mEngine.GetMouseY());
	//	mYellowDiamondX = mEngine.GetMouseX();
	//	mYellowDiamondY = mEngine.GetMouseY();
	}
/*	mEngine.Render(King::Engine::TEXTURE_GREEN, 650.0f, 100.0f);
	mEngine.Render(King::Engine::TEXTURE_RED, 100.0f, 450.0f);
	mEngine.Render(King::Engine::TEXTURE_BLUE, 650.0f, 450.0f);

	mEngine.Write("Green", 100.0f, 140.0f);
	mEngine.Write("Red", 100.0f, 490.0f);
	mEngine.Write("Blue", 650.0f, 490.0f);

	const char text[] = "This rotates at 5/PI Hz";
	mRotation += mEngine.GetLastFrameSeconds();
	mEngine.Write(text, mEngine.GetWidth() / 2.0f, mEngine.GetHeight() / 2.0f, mRotation * 2.5f);

	if (mEngine.GetMouseButtonDown()) {

		mYellowDiamondX = mEngine.GetMouseX();
		mYellowDiamondY = mEngine.GetMouseY();
	}
	mEngine.Render(King::Engine::TEXTURE_YELLOW, mYellowDiamondX, mYellowDiamondY);
	mEngine.Write("Click to", mYellowDiamondX, mYellowDiamondY + 0.0f);
	mEngine.Write("move me!", mYellowDiamondX, mYellowDiamondY + 70.0f);*/
}




void LevelScene::removeMatchedNodes(std::vector<int> markedNodes) {

	for (unsigned int i = 0; i < markedNodes.size(); i++) {

		mlevelColors[markedNodes[i]] = -1; // Marked removed nodes to be -1 
		jewelers[markedNodes[i]] = nullptr;
	}

}

void LevelScene::fillTopVector()
{
	for (size_t i = GAME_MAX_CELLS; i < mlevelColors.size(); i++)
	{

		if (mlevelColors[i] == -1) {
			
			mlevelColors[i] =  rand() % 5;

				jewelers[i] = std::move(std::make_shared<JewelryItem>(mlevelColors[i] +1 , 0, 0, 35, 35));
		
		}

	}
}

void LevelScene::nodesGravityCheck(std::vector<int>& markedNodes)
{

	bool isVertical = false;
	bool isHorizontal = false;

	if (markedNodes.size() < GAME_MINMUM_MATCHED) // minum matched number 3 in our case
		return;

	uint32_t lastNodeIndex = markedNodes.size() - 1;
	uint32_t maxNodePerCol = markedNodes[lastNodeIndex] + GAME_COL_MAX;
	if (maxNodePerCol > mlevelColors.size() - 1) // back point to move all points to up
		return;

	if (markedNodes[0] == markedNodes[1] - 1)
	{
		isHorizontal = true;
	}
	else {
		// return point needed only in vertical matches
		isVertical = true;

		uint32_t maxNodeForCol = markedNodes[lastNodeIndex] + markedNodes.size() * GAME_COL_MAX;
		if (maxNodeForCol > mlevelColors.size() - 1) // back point to move all points to up
			return;

	}


	if (isVertical) {

		int j = 0;

		for (int col = markedNodes.size() - 1; col >= 0; col--)
		{

			int removedNodeId = markedNodes[col];

			int nodeColor = mlevelColors[removedNodeId];

			std::weak_ptr<Item>  removedNodeItem = jewelers[removedNodeId];
			std::shared_ptr<Item>  deletedNode = jewelers[removedNodeId];

			if (nodeColor == -1) {

				uint32_t nodeTobeMoved = removedNodeId + markedNodes.size() * GAME_COL_MAX;

				std::shared_ptr<Item>  nodeTobMovedItem = jewelers[nodeTobeMoved];


				if (nodeTobeMoved < mlevelColors.size()) {

					mlevelColors[removedNodeId] = mlevelColors[nodeTobeMoved];

					markedNodes[col] = nodeTobeMoved;
					

					jewelers[removedNodeId] = nodeTobMovedItem;
					
					if (nodeTobeMoved < GAME_MAX_CELLS) {
						jewelers[removedNodeId]->animate(true);
					}
					else {
						jewelers[removedNodeId]->animate(false);
					}

				}
				else {

					mlevelColors[removedNodeId] = rand() % 5;
				}

				mlevelColors[nodeTobeMoved] = -1;
				
				jewelers[nodeTobeMoved] = nullptr;
			
			}

		}
	}
	else {

		for (int row = markedNodes.size() - 1; row >= 0; row--) {
			int removedNodeId = markedNodes[row];

			int nodeColor = mlevelColors[removedNodeId];
			if (nodeColor == -1) {

				uint32_t nodeTobeMoved = removedNodeId + GAME_COL_MAX;
				std::shared_ptr<Item> nodeTobMovedItem = jewelers[nodeTobeMoved];
				std::shared_ptr<Item> deletedNode = jewelers[removedNodeId];
				if (nodeTobeMoved < mlevelColors.size()) {
					mlevelColors[removedNodeId] = mlevelColors[nodeTobeMoved];

					jewelers[removedNodeId] = nodeTobMovedItem;

					markedNodes[row] = nodeTobeMoved;

					if (nodeTobeMoved < GAME_MAX_CELLS) {
						jewelers[removedNodeId]->animate(true);
					}
					else {
						jewelers[removedNodeId]->animate(false);
					}


				}
				else {

					mlevelColors[removedNodeId] = rand() % 5;

				}
				mlevelColors[nodeTobeMoved] = -1;
				
				jewelers[nodeTobeMoved] = nullptr;
			}

		}

	}


	nodesGravityCheck(markedNodes); // make sure all nodes to move up

}