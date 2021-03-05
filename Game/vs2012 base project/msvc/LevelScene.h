#pragma once
#include "MainScene.h"
class LevelScene: public MainScene
{
public:
	LevelScene() : MainScene()
	{
	}

	virtual void Update();
	virtual void Start();
};

