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
#include "CommandManager.h"
#include <memory>

class LevelScene: public MainScene,public Level
{
public:
	LevelScene() : MainScene()
	{
		init();
		load();
	}

	~LevelScene() {

		delete board;
		delete mBackground;

	}


	virtual void load();
	virtual void end();
	virtual void won();

	virtual void Update();
	virtual void Start();

private:
	void init();

protected:
	std::vector<int> mlevelColors;
	std::vector<Item*> jewelers;
private:
	Board* board;
	BackgroundItem *mBackground;
	std::shared_ptr<CommandManager> mCommandManager;


};

