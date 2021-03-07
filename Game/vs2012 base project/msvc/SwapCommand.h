#pragma once
#include "Command.h"
#include <vector>
#include "Match3Graph.h"
#include <memory>
class Item;

class SwapCommand :
    public Command
{
public:
	SwapCommand(int fNode, int sNode ,
		std::vector<int> & mlevelColors,
		std::vector<std::shared_ptr<Item>> & jewelers, std::shared_ptr<Match3Graph> &match3Graph)
	:mFistNodeId(fNode), mSecondNodeId(sNode),
		mlevelColors(mlevelColors), jewelers(jewelers), mMatch3Graph(match3Graph)
	{

	}

	~SwapCommand() {
	
	}

public:
	void execute();
	bool isFinished();


private:
	int mFistNodeId;
	int mSecondNodeId;
	bool mCompleted;
	std::shared_ptr<Match3Graph> &mMatch3Graph;
	std::vector<int> &mlevelColors;
	std::vector<std::shared_ptr<Item>> &jewelers;
	std::vector<std::vector<int>> swapNodes(int first, int second);
};

