#include "Board.h"
#include <iostream>
void Board::update(King::Engine& engine)
{
	if (engine.GetMouseButtonDown())
	{
		float mouseX = engine.GetMouseX();
		float mouseY = engine.GetMouseY();

		if (isToucheWithinBoard(mouseX, mouseY)) {
		
			std::cout << "Within Range";
			mDraggedItemIndex = 5;

			levelColoredItems[mDraggedItemIndex]->setLocation(mouseX, mouseY);
		}
		else {
		
			mDraggedItemIndex = -1;
		}



	}

	for (unsigned i = 0 ; i < levelColoredItems.size(); i++ )
	{
		std::tuple<int, int> location = Match3Graph::findNodeLocationById(i);
	
		int row = std::get<0>(location);
		int col = std::get<1>(location);
		int x = mX + col * mCellWidth;
		int y = mY + row * mCellHeight;

		if(i != mDraggedItemIndex)
		levelColoredItems[i]->setLocation(x, y);

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
			(mouseY > mY && mouseY < mY + mHeight)
	   )
		return true;

	return false;
}
