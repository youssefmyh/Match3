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
	*
	*/
	void update(King::Engine& engine);

	/*update
	*
	*/
	void move(int x, int y);

	/*update
	*
	*/
	void setLocation(int x, int y);	

	/*update
	*
	*/
	std::tuple<int, int> getBoardLocation();


};

