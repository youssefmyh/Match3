#include "Board.h"

void Board::update()
{

}

void Board::draw(King::Engine& engine)
{
	for each (Item* je in levelColoredItems)
	{
		je->draw(engine);
	}

}

void Board::move(float x, float y)
{
}
