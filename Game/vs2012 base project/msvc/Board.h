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
	
	/*update
	*
	*/
	void update(King::Engine& engine);

	/*move
	*
	*/
	void move(int x, int y);

	/*setLocation
	*
	*/
	void setLocation(int x, int y);

	/*update
	*findItemIdByLocation
	* @param float mouseX 
	* f@param float mouseY
	*/
	int findItemIdByLocation(float mouseX, float mouseY);

private:
	std::vector<Item*>  levelColoredItems;
	bool isToucheWithinBoard(float x, float y);
	void nodeMouseCheck(King::Engine& engine);

	/*swapTwoNodes
	/*@param int nodeId
	/*@param Direction (UP,DOWN,RIGHT,LEFT)
	*/
	void swapTwoNodes(int nodeId, Direction direction);

	int mCellHeight;
	int mCellWidth;
	int mDraggedItemIndex;
	float mStartMouseX;
	float mStartMouseY;
	bool isSwaping;
};

