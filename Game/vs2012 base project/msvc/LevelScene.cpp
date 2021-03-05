#include "LevelScene.h"


void LevelScene::Start() {
	mEngine.Start(*this);
}

void LevelScene::load()
{
	mBackground = new BackgroundItem(0, 0, 0);
	mlevelColors = LevelRepository::findLevelById(1);
	mMatch3Graph->setNodesColors(mlevelColors);

	std::vector<Item*> jewelers;

	int textureWidth = mEngine.GetTextureWidth(King::Engine::Texture::TEXTURE_BLUE);
	int textureHeight = mEngine.GetTextureWidth(King::Engine::Texture::TEXTURE_BLUE);
	int boardXLocation = std::get<0>(mBackground->getBoardLocation());
	int boardYLocation = std::get<1>(mBackground->getBoardLocation());

	for (uint32_t i = 0;  i< GAME_MAX_CELLS;  i++)
	{
		std::tuple<int,int> location = mMatch3Graph->findNodeLocationById(i);
		int row = std::get<0>(location);
		int col = std::get<1>(location);
		int x = boardXLocation + col * textureHeight;
		int y = boardYLocation + row * textureWidth;

		JewelryItem *jItem = new JewelryItem(mlevelColors[i]+1, x, y);
		jewelers.push_back(jItem);
	}

	board = new Board(0, 0, 0, std::move(jewelers), textureWidth, textureHeight);

}

void LevelScene::end()
{
}

void LevelScene::won()
{
}

void LevelScene::Update() {

	mBackground->draw(mEngine);
	board->draw(mEngine);


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