#pragma once
#include <king/Engine.h>
#include <king/Updater.h>
class Item {

public:
	
	Item(int itemId,int x ,int y) :mTexture((King::Engine::Texture)itemId),mItemId(itemId), mX(x),mY(y),mToX(x), mToY(y) {}
	virtual void update(King::Engine& engine) = 0;
	//virtual void draw(King::Engine& engine) = 0;
	virtual void move(int x , int y) = 0;
	virtual void setLocation(int x, int y) = 0;

	int getItemId() const {
		
		return mItemId;
	}

	int getX() const {
		
		return mX;
	}

	int getY() const {
		
		return mY;
	}

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