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
	Board(int itemId, int x, int y, std::vector<int> & nodeColors, std::vector<std::shared_ptr<Item>> & jewelersItems, 
		int cellWidth, int cellHeight , std::shared_ptr<CommandManager> cmdManager, std::shared_ptr<Match3Graph> match3Graph)
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
	
		mjewelersItems.clear();
		

	}
	

	/*update
	*@param King engine
	*/
	void update(King::Engine& engine);

	/*move
	*@param x
	* @param y
	*/
	void move(int x, int y);

	/*setLocation
	*@param x
	* @param y
	*/
	void setLocation(int x, int y);

	/*update
	*findItemIdByLocation
	* @param float mouseX 
	* f@param float mouseY
	*/
	int findItemIdByLocation(float mouseX, float mouseY);


private:

	/*isToucheWithinBoard
	* check if the mouse inside the Board
	/*@param int x
	* @param int y
	*/
	bool isToucheWithinBoard(float x, float y);

	/*nodeMouseCheck
	/*@param Engine
	*/
	void nodeMouseCheck(King::Engine& engine);
	/*swapTwoNodes
	/*@param int nodeId
	/*@param Direction (UP,DOWN,RIGHT,LEFT)
	*/
	void swapTwoNodes(int nodeId, int direction);

private:
	std::vector<std::shared_ptr<Item>> & mjewelersItems; // jewelers items passed by reference it work like a view for the nodes color
	std::vector<int> &nodeColors; //  nodes colors it's work like a core or the data of jewelers
	int mCellHeight; // cell hegith
	int mCellWidth; // cell width
	int mDraggedItemIndex; // draged item
	float mStartMouseX; // start Touch X
	float mStartMouseY; //  start Touch Y
	bool isSwaping; // is Swaping 
	std::shared_ptr<Match3Graph> mMatch3Graph; // pointer to graph algorthim

	std::shared_ptr<CommandManager> mCommandManager; // command manager

};

