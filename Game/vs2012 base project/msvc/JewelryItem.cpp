#include "JewelryItem.h"

void JewelryItem::update()
{
	if (mToY > mY) {
		mY++;
	}
	
}

void JewelryItem::draw(King::Engine& engine)
{
	engine.Render(mTexture, mX, mY);

}

void JewelryItem::move(int x, int y)
{
	mToX = x;
	mToY = y;
}
