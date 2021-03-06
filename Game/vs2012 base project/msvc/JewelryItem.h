#pragma once
#include "Item.h"
class JewelryItem :public Item
{
public:
	JewelryItem(int itemId, int x, int y,int width,int height) :Item(itemId,x,y)
	{
		mWidth = width;
		mHeight = height;
	}
	void update(King::Engine& engine);
	void move(int x , int y);
	void setLocation(int x, int y);
};

