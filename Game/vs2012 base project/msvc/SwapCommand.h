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
	int mFistNodeId; // first node id to be swapped
	int mSecondNodeId; // second node id
	bool mCompleted; // is animation completed
	std::shared_ptr<Match3Graph> &mMatch3Graph; // match3 algorthim reference 

	std::vector<int> &mlevelColors; // level color referece need to be renamed to be nodeColors
	std::vector<std::shared_ptr<Item>> &jewelers;  // jewelers reference 

	/*swapNodes
	* @param int first node
	* @param int second node
	*/
	std::vector<std::vector<int>> swapNodes(int first, int second); // 
};

