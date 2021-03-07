#include "Item.h"

int Item::getItemId() const {

	return mItemId;
}

int Item::getX() const {

	return mX;
}

int Item::getY() const {

	return mY;
}

void Item::animate(bool animate)
{
	mAnimate = animate;
}

bool Item::isAnimate() const
{
	return mAnimate;
}

void Item::setTemporaryLocation(int x, int y) {

	if (tempX != -1 && tempY != -1)
	{
		if ((x < mX - mWidth || x > mX + mWidth) && y == mY)
			return;

		if ((y < mY - mHeight || y > mY + mHeight) && x == mX)
			return;
	}

	tempX = x;
	tempY = y;




}