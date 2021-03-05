#pragma once
#include "Item.h"
#include <tuple>

class BackgroundItem :
    public Item
{
public:
	BackgroundItem(int itemId, float x, float y) :Item(itemId, x, y){}
	void update();
	void draw(King::Engine& engine);
	void move(float x, float y);
	
	std::tuple<int, int> getBoardLocation();


};

