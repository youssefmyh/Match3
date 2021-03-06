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
	int getX() const;
	int getY() const;
	int getItemId() const;
	void setTemporaryLocation(int x, int y);


protected:
	int mItemId;
	King::Engine::Texture mTexture;
	int mToX;
	int mToY;
	int mX;
	int mY;
	int tempX = -1 ;
	int tempY = -1;
	int mWidth;
	int mHeight;
};