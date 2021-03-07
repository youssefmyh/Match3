#include "PointsItem.h"

void PointsItem::update(King::Engine& engine)
{

	std::string score("Score : ");
	score += std::to_string(mPoints);
	engine.Write(&score[0], mX, mY);
}

void PointsItem::move(int x, int y)
{
}

void PointsItem::addPoints(int points)
{
	mPoints += points * GAME_POINT_FACTOR;
}

void PointsItem::setLocation(int x, int y)
{
}
