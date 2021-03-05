#pragma once
#include "Item.h"
class JewelryItem :public Item
{
public:
	JewelryItem(int itemId, int x, int y) :Item(itemId,x,y){}
	void update();
	void draw(King::Engine& engine);
	void move(int x , int y);

};

