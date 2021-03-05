#pragma once
#include "JewelryItem.h"
#include <vector>
#include "Match3Settings.h"
class Board :public Item
{
public:
	Board(int itemId, int x, int y, std::vector<Item*> & levelColoredItems, int cellWidth, int cellHeight) : Item(itemId, x, y), levelColoredItems(levelColoredItems)
	{
		mWidth = GAME_ROW_MAX * cellWidth;
		mHeight = GAME_COL_MAX * cellHeight;

	}

	~Board() {
	
		for each (Item * item in levelColoredItems)
		{
			delete item;
		}

	}
	void update();
	void draw(King::Engine& engine);
	void move(int x, int y);

private:
	std::vector<Item*>  levelColoredItems;


};

