#pragma once
#include "Item.h"
#include <tuple>

class BackgroundItem :
    public Item
{
public:

	/*update
	*
	*/
	BackgroundItem(int itemId, int x, int y) :Item(itemId, x, y){}

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

	/*getBoardLocation
	*@return tuple of x and y
	*/
	std::tuple<int, int> getBoardLocation();


};

