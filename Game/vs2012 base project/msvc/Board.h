#pragma once
#include "JewelryItem.h"
#include <vector>
#include "Match3Settings.h"
#include "CommandManager.h"
#include <memory>
#include "Match3Graph.h"

enum Direction {
	UP,DOWN,RIGHT,LEFT
};

class Board :public Item
{
public:
	Board(int itemId, int x, int y, std::vector<int> & nodeColors, std::vector<Item*> & jewelersItems, 
		int cellWidth, int cellHeight , std::shared_ptr<CommandManager> cmdManager, Match3Graph * match3Graph)
		:
		Item(itemId, x, y),nodeColors(nodeColors),
		mjewelersItems(jewelersItems),
		mCellWidth(cellWidth),mCellHeight(cellHeight), mMatch3Graph(match3Graph)
	{
		this->mCommandManager = cmdManager;
		mWidth =  GAME_ROW_MAX * cellWidth;
		mHeight = GAME_COL_MAX * cellHeight;

	}

	~Board() {
	
		for each (Item * item in mjewelersItems)
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
	std::vector<Item*> & mjewelersItems;
	std::vector<int> &nodeColors;
	bool isToucheWithinBoard(float x, float y);
	void nodeMouseCheck(King::Engine& engine);


	/*swapTwoNodes
	/*@param int nodeId
	/*@param Direction (UP,DOWN,RIGHT,LEFT)
	*/
	void swapTwoNodes(int nodeId, int direction);

	int mCellHeight;
	int mCellWidth;
	int mDraggedItemIndex;
	float mStartMouseX;
	float mStartMouseY;
	bool isSwaping;
	Match3Graph* mMatch3Graph;

	std::shared_ptr<CommandManager> mCommandManager; // command manager

};

