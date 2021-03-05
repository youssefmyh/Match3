#pragma once
#include "JewelryItem.h"
#include <vector>
#include "Match3Settings.h"
#include "Match3Graph.h"

enum Direction {

	UP,DOWN,RIGHT,LEFT


};

class Board :public Item
{
public:
	Board(int itemId, int x, int y, std::vector<Item*> & levelColoredItems, int cellWidth, int cellHeight) : 
		Item(itemId, x, y), levelColoredItems(levelColoredItems),mCellWidth(cellWidth),mCellHeight(cellHeight)
	{
		mWidth =  GAME_ROW_MAX * cellWidth;
		mHeight = GAME_COL_MAX * cellHeight;

	}

	~Board() {
	
		for each (Item * item in levelColoredItems)
		{
			delete item;
		}

	}
	void update(King::Engine& engine);
	void move(int x, int y);
	void setLocation(int x, int y);
	int findItemIdByLocation(float mouseX, float mouseY);
private:
	std::vector<Item*>  levelColoredItems;
	bool isToucheWithinBoard(float x, float y);
	int mCellHeight;
	int mCellWidth;
	int mDraggedItemIndex;
	float mStartMouseX;
	float mStartMouseY;
};

