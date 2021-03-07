#pragma once
#include <king/Engine.h>
#include <king/Updater.h>


class Item {

public:
	
	Item(int itemId,int x ,int y) :mTexture((King::Engine::Texture)itemId),mItemId(itemId), mX(x),mY(y),mToX(x), mToY(y) 
	{}
	
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

	/*animate
	* animate a specific item
	* @param animate
	*/
	void animate(bool animate);

	/*isAnimate
	* retrun true if item animating
	*/
	bool isAnimate() const;


protected:
	int mItemId; // item Id which linked to range of color( 0 -- 4)
	King::Engine::Texture mTexture; // Texture Id which linked to range of color( 0 -- 4)
	int mToX; // move to specific X location 
	int mToY; // move to specific Y Location 
	int mX; // mX Item X
	int mY;  // Item Y
	int tempX = -1 ; // TempX and Temp Y value used for animation 
	int tempY = -1; // 
	int mWidth; // Item width
	int mHeight; // item Height
	bool mAnimate = false; /// is item animating 

};