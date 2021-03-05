#pragma once
#include <king/Engine.h>
#include <king/Updater.h>
#include "Match3Graph.h"
#include "JewelryItem.h"
class MainScene : public King::Updater
{
public:
	MainScene() : mEngine("./assets") 
		, mRotation(0.0f)
		, mYellowDiamondX(100.0f)
		, mYellowDiamondY(100.0f) 
	{
		mMatch3Graph = new Match3Graph();
		mewelryItem = new JewelryItem(1, 100, 200);
	}

	
	~MainScene() {
	
		delete mMatch3Graph;
	}

	virtual void load() = 0;
	virtual void end();
	virtual void won();

public:
	/*
	* King Engine Functions
	*/
	virtual void Update() = 0;
	virtual void Start() = 0;
	

protected:
	King::Engine mEngine;
	Match3Graph* mMatch3Graph;
	JewelryItem *mewelryItem;
	float mRotation;
	float mYellowDiamondX;
	float mYellowDiamondY;
};

