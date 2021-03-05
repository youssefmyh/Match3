#include "BackgroundItem.h"

void BackgroundItem::update()
{
	

}

void BackgroundItem::draw(King::Engine& engine)
{
	engine.Render(mTexture, mX, mY);

}

void BackgroundItem::move(float x, float y)
{
	
}

std::tuple<int, int> BackgroundItem::getBoardLocation()
{
	return std::tuple<int, int>(200,200);
}
