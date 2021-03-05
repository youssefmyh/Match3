#pragma once
//  Created by Youssef Hanna.
//  Copyright © 2021. All rights reserved.
//
/*
* LevelScene
* First Level 
*/
#include "MainScene.h"
#include "Level.h"
#include "LevelRepository.h"
#include "Board.h"
#include "BackgroundItem.h"
class LevelScene: public MainScene,public Level
{
public:
	LevelScene() : MainScene()
	{
		load();
	}


	virtual void load();
	virtual void end();
	virtual void won();

	virtual void Update();
	virtual void Start();

protected:
	std::vector<int> mlevelColors;
private:
	Board* board;
	BackgroundItem *mBackground;

};

