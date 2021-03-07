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
#include "FillCommand.h"
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

	/*
	* Level Interface load end , won
	*/
	virtual void load();
	virtual void end();
	virtual void won();

	/*
	* Level Interface load end , won
	*/
	virtual void Update();
	virtual void Start();

private:
	void init();

protected:
	std::vector<int> mlevelColors;
	std::vector<std::shared_ptr<Item>> jewelers;
private:
	Board* board;
	BackgroundItem *mBackground;
	std::shared_ptr<CommandManager> mCommandManager;


private:

	void nodesGravityCheck(std::vector<int>& markedNodes);
	std::vector<std::vector<int>> swapNodes(int first, int second);
	void removeMatchedNodes(std::vector<int> markedNodes);

	void fillTopVector();
};

