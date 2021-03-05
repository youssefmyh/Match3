#pragma once
#include "JewelryItem.h"
#include <vector>
class Board :public Item
{
public:
	Board(int itemId, float x, float y, std::vector<Item*> & levelColoredItems) : Item(itemId, x, y), levelColoredItems(levelColoredItems)
	{

	}
	void update();
	void draw(King::Engine& engine);
	void move(float x, float y);

private:
	std::vector<Item*>  levelColoredItems;


};

