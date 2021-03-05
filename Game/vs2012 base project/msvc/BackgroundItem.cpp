#include "BackgroundItem.h"

void BackgroundItem::update()
{
	

}

void BackgroundItem::draw(King::Engine& engine)
{
	engine.Render(mTexture, mX, mY);

}

void BackgroundItem::move(int x, int y)
{
	
}

std::tuple<int, int> BackgroundItem::getBoardLocation()
{
	return std::tuple<int, int>(350,125);
}
