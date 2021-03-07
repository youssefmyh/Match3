#pragma once
#include "Command.h"
class TestCommand :
    public Command
{
public:
	TestCommand()
	{

	}

	~TestCommand() {

	}

public:
	void execute();
	bool isFinished();


private:
	bool mCompleted;
};

