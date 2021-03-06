#include "Board.h"
#include <iostream>
void Board::update(King::Engine& engine)
{
	if (engine.GetMouseButtonDown()){

	
		float mouseX = engine.GetMouseX();
		float mouseY = engine.GetMouseY();

		if (mStartMouseX == -1) {

			mStartMouseX = mouseX;
			mStartMouseY = mouseY;
		}

		
		


		if (isToucheWithinBoard(mouseX, mouseY)) {
		
		
			if (mDraggedItemIndex == -1)
				mDraggedItemIndex = findItemIdByLocation(mouseX, mouseY);


			int mouseDifferenceX = mouseX - mStartMouseX;
			int mouseDifferenceY = mouseY - mStartMouseY;

			int xLocation = levelColoredItems[mDraggedItemIndex]->getX() + mouseDifferenceX;
			int yLocation = levelColoredItems[mDraggedItemIndex]->getY() + mouseDifferenceY;

			if (mouseX > mStartMouseX + GAME_DEAG_PADDING || mouseX < mStartMouseX - GAME_DEAG_PADDING) {
			
				levelColoredItems[mDraggedItemIndex]->setTemporaryLocation(xLocation, levelColoredItems[mDraggedItemIndex]->getY());

			}else
				
				if (mouseY > mStartMouseY + GAME_DEAG_PADDING || mouseY < mStartMouseY - GAME_DEAG_PADDING) {
					levelColoredItems[mDraggedItemIndex]->setTemporaryLocation(levelColoredItems[mDraggedItemIndex]->getX(), yLocation);
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
	}

	for (unsigned i = 0 ; i < levelColoredItems.size(); i++ )
	{
		std::tuple<int, int> location = Match3Graph::findNodeLocationById(i);
	
		int row = std::get<0>(location);
		int col = std::get<1>(location);
		int x = mX + col * mCellWidth;
		int y = mY - (row+1) * mCellHeight;

		if (i != mDraggedItemIndex) {

			levelColoredItems[i]->setLocation(x, y);
			levelColoredItems[i]->setTemporaryLocation(-1, -1);
		}
		

		levelColoredItems[i]->update(engine);

		
	}

	


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

int Board::findItemIdByLocation(float mouseX, float mouseY)
{
	int acualX = mouseX - mX;
	int acualY = mY - mouseY ;
	
	int itemId = int(floor(acualX / mCellWidth))  + int(floor(acualY / mCellHeight)) * GAME_ROW_MAX;
		std::cout << itemId << "\n";


	return itemId;
}
