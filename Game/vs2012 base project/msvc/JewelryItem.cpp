#include "JewelryItem.h"
#include <king/Engine.h>
void JewelryItem::update(King::Engine& engine)
{
	if (mToY > mY) {
		mY = mY + 25;
	}
	else {
		mAnimate = false;
	}
	
	engine.Render(mTexture, tempX != -1 ? tempX : mX, tempY != -1 ? tempY : mY);

}


void JewelryItem::move(int x, int y)
{
	mToX = x;
	mToY = y;
}

void JewelryItem::setLocation(int x, int y)
{
	mX = x;

	if (mAnimate)
	{
		mToY = y;
	}
	else {

		mY = y;

	}

}