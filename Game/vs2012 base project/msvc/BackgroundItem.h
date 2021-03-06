#pragma once
#include "Item.h"
#include <tuple>

class BackgroundItem :
    public Item
{
public:
	BackgroundItem(int itemId, int x, int y) :Item(itemId, x, y){}
	void update(King::Engine& engine);
	void move(int x, int y);
	void setLocation(int x, int y);	
	std::tuple<int, int> getBoardLocation();


};

