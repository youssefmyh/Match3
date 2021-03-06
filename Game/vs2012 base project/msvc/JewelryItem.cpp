#include "JewelryItem.h"

void JewelryItem::update(King::Engine& engine)
{
	if (mToY > mY) {
		mY++;
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
	mY = y;
}