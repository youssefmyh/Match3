#include "JewelryItem.h"

void JewelryItem::update()
{
	if (mToY > mY) {
		mY++;
	}
	
}

void JewelryItem::draw(King::Engine& engine)
{
	engine.Render(King::Engine::TEXTURE_GREEN, mX, mY);

}

void JewelryItem::move(float x, float y)
{
	mToX = x;
	mToY = y;
}
