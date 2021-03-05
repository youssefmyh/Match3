#pragma once
#include <king/Engine.h>
#include <king/Updater.h>
class Item {

public:
	
	Item(int itemId,float x ,float y) :mTexture((King::Engine::Texture)itemId),mItemId(itemId), mX(x),mY(y),mToX(x), mToY(y) {}
	virtual void update() = 0;
	virtual void draw(King::Engine& engine) = 0;
	virtual void move(float x ,float y) = 0;
	
protected:
	int mItemId;
	King::Engine::Texture mTexture;
	float mToX;
	float mToY;
	float mX;
	float mY;
};