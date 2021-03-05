#include "BackgroundItem.h"

void BackgroundItem::update(King::Engine& engine)
{
	
	engine.Render(mTexture, mX, mY);

}


void BackgroundItem::move(int x, int y)
{
	
}

void BackgroundItem::setLocation(int x, int y)
{
	mX = x;
	mY = y;
}

std::tuple<int, int> BackgroundItem::getBoardLocation()
{
	return std::tuple<int, int>(350,375);
}
