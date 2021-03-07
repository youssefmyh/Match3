#pragma once
#include <king/Engine.h>
#include <king/Updater.h>

class Item {

public:
	
	Item(int itemId,int x ,int y) :mTexture((King::Engine::Texture)itemId),mItemId(itemId), mX(x),mY(y),mToX(x), mToY(y) {}
	
	/*update
	*
	*/
	virtual void update(King::Engine& engine) = 0;
	
	/*move
	*
	*/
	virtual void move(int x , int y) = 0;
	
	/*setLocation
	*
	*/
	virtual void setLocation(int x, int y) = 0;
	
	/*getX
	*
	*/
	int getX() const;
	
	/*getY
	*
	*/
	int getY() const;
	
	/*getItemId
	*
	*/
	int getItemId() const;

	/*setTemporaryLocation
	* 
	*/
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