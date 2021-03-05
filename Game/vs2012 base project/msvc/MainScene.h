#pragma once
#include <king/Engine.h>
#include <king/Updater.h>
class MainScene : public King::Updater
{
public:
	MainScene() : mEngine("./assets") 
		, mRotation(0.0f)
		, mYellowDiamondX(100.0f)
		, mYellowDiamondY(100.0f) 
	{
	}

	virtual void Update() = 0;
	virtual void Start() = 0;

protected:
	King::Engine mEngine;
	float mRotation;
	float mYellowDiamondX;
	float mYellowDiamondY;
};

