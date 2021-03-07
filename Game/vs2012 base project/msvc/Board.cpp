#include "Board.h"
#include "SwapCommand.h"
void Board::update(King::Engine& engine)
{

	for (unsigned i = 0 ; i < mjewelersItems.size(); i++ )
	{
		std::tuple<int, int> location = Match3Graph::findNodeLocationById(i);
	
		int row = std::get<0>(location);
		int col = std::get<1>(location);
		int x = mX + col * mCellWidth;
		int y = mY - (row+1) * mCellHeight;

		if (mjewelersItems[i] == nullptr) {
		
			continue;
		}
		if (i != mDraggedItemIndex ) {

			mjewelersItems[i]->setLocation(x, y);
			mjewelersItems[i]->setTemporaryLocation(-1, -1);
		}
		mjewelersItems[i]->update(engine);
		
	}

	nodeMouseCheck(engine);

}


void Board::move(int x, int y)
{
}

void Board::setLocation(int x, int y)
{
	mX = x;
	mY = y;
}


bool Board::isToucheWithinBoard(float mouseX, float mouseY)
{
	if (	(mouseX > mX && mouseX < mX + mWidth) 
		&&  
			(mouseY < mY && mouseY > mY - mHeight)
	   )
		return true;

	return false;
}

void Board::nodeMouseCheck(King::Engine& engine)
{
	if (engine.GetMouseButtonDown()) {


		float mouseX = engine.GetMouseX();
		float mouseY = engine.GetMouseY();

		if (mStartMouseX == -1) {

			mStartMouseX = mouseX;
			mStartMouseY = mouseY;
		}


		if (isToucheWithinBoard(mouseX, mouseY) && !isSwaping) {

			if (mDraggedItemIndex == -1)
				mDraggedItemIndex = findItemIdByLocation(mouseX, mouseY);

			int mouseDifferenceX = mouseX - mStartMouseX;
			int mouseDifferenceY = mouseY - mStartMouseY;

			int xLocation = mjewelersItems[mDraggedItemIndex]->getX() + mouseDifferenceX;
			int yLocation = mjewelersItems[mDraggedItemIndex]->getY() + mouseDifferenceY;

			if (mouseX > mStartMouseX + GAME_DEAG_PADDING || mouseX < mStartMouseX - GAME_DEAG_PADDING) {


				mjewelersItems[mDraggedItemIndex]->setTemporaryLocation(xLocation, mjewelersItems[mDraggedItemIndex]->getY());
				

				if (mouseX > mStartMouseX + GAME_DEAG_PADDING) {

					swapTwoNodes(mDraggedItemIndex, RIGHT);
				}
				else {
					swapTwoNodes(mDraggedItemIndex, LEFT);
				}


			}
			else
				if (mouseY > mStartMouseY + GAME_DEAG_PADDING || mouseY < mStartMouseY - GAME_DEAG_PADDING) {

					if (mouseY < mStartMouseY - GAME_DEAG_PADDING) {
						swapTwoNodes(mDraggedItemIndex, UP);
					}
					else {
						swapTwoNodes(mDraggedItemIndex, DOWN);
					}
					mjewelersItems[mDraggedItemIndex]->setTemporaryLocation(mjewelersItems[mDraggedItemIndex]->getX(), yLocation);

				}
		}
		else {

			mDraggedItemIndex = -1;
		}


	}
	else {
		mStartMouseX = -1;
		mStartMouseY = -1;
		mDraggedItemIndex = -1;
		isSwaping = false;
	}
}

int Board::findItemIdByLocation(float mouseX, float mouseY)
{
	int acualX = mouseX - mX;
	int acualY = mY - mouseY ;
	
	int itemId = int(floor(acualX / mCellWidth))  + int(floor(acualY / mCellHeight)) * GAME_ROW_MAX;

	return itemId;
}

void Board::swapTwoNodes(int nodeId, int direction)
{
	isSwaping = true;
	int swapedNodeId = -1;
	switch (direction)
	{
	case UP:
		swapedNodeId = nodeId + GAME_COL_MAX;
		break;
	case DOWN:
		swapedNodeId = nodeId - GAME_COL_MAX;
		break;  
	case RIGHT:
		swapedNodeId = nodeId + 1;
		break;
	case LEFT:
		swapedNodeId = nodeId - 1;
		break;
	default:
		break;
	}

	if (swapedNodeId < 0 || swapedNodeId > GAME_MAX_CELLS -1 )
		return;

	SwapCommand* swap = new SwapCommand(nodeId, swapedNodeId, nodeColors, mjewelersItems, mMatch3Graph);
	mCommandManager->addCommand(std::move(swap));
	/*Item *fitem = mjewelersItems[nodeId];
	Item* sItem = mjewelersItems[swapedNodeId];
	mjewelersItems[nodeId] = sItem;
	mjewelersItems[swapedNodeId] = fitem;
	
	nodeColors[nodeId] = fitem->getItemId();
	nodeColors[swapedNodeId] = sItem->getItemId();

	*/

}


