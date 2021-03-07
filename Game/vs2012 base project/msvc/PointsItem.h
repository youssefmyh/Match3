#pragma once
#include "Item.h"
#include <string>
#include "Match3Settings.h"
class PointsItem :
    public Item
{
public:

	/*update
	*
	*/
	PointsItem(int itemId, int x, int y) :Item(itemId, x, y) {}

	/*update
	*@param King engine
	*/
	void update(King::Engine& engine);

	/*move
	*@param x
	* @param y
	*/
	void move(int x, int y);


	/*addPoints
	*@param int points
	*/
	void addPoints(int points);


	/*setLocation
	*@param x
	* @param y
	*/
	void setLocation(int x, int y);


private:
	int mPoints = 0;



};

