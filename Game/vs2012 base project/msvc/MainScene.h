#pragma once
#include <king/Engine.h>
#include <king/Updater.h>
#include "Match3Graph.h"
#include "JewelryItem.h"
class MainScene : public King::Updater
{
public:
	MainScene() : mEngine("./assets") 
	{
	}

	
	~MainScene() {
	
		delete mMatch3Graph;
	}

	/*update
	*
	*/
	virtual void load() = 0;

	/*update
	*
	*/
	virtual void end();

	/*update
	*
	*/
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

};

