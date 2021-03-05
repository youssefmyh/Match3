#pragma once
#include <king/Engine.h>
#include <king/Updater.h>
class Item {

public:
	
	Item(int itemId,int x ,int y) :mTexture((King::Engine::Texture)itemId),mItemId(itemId), mX(x),mY(y),mToX(x), mToY(y) {}
	virtual void update() = 0;
	virtual void draw(King::Engine& engine) = 0;
	virtual void move(int x , int y) = 0;
	
protected:
	int mItemId;
	King::Engine::Texture mTexture;
	int mToX;
	int mToY;
	int mX;
	int mY;
	int mWidth;
	int mHeight;
};