#pragma once
#include "Command.h"
class SwapCommand :
    public Command
{
	SwapCommand(int fNode, int sNode) :mFistNodeId(fNode), mSecondNodeId(sNode){
	}


public:
	void execute();
	bool isFinished();


private:
	int mFistNodeId;
	int mSecondNodeId;
};

