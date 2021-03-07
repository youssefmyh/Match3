#pragma once
#include "Command.h"
#include <vector>
#include "Match3Graph.h"
#include <memory>
class RemoveMatchedCommand :
    public Command
{

public:
	RemoveMatchedCommand(std::vector<int> &matchedNodes,
		std::vector<int>& mlevelColors,
		std::vector<std::shared_ptr<Item>>& jewelers, std::shared_ptr<Match3Graph>& match3Graph):
		mlevelColors(mlevelColors), jewelers(jewelers), mMatch3Graph(match3Graph), mMatchedNodes(matchedNodes)
	{

	}

	~RemoveMatchedCommand() {

	}

public:
	void execute();
	bool isFinished();


private:
	bool mCompleted; // is animation completed
	std::shared_ptr<Match3Graph>& mMatch3Graph; // match3 algorthim reference 

	std::vector<int>& mlevelColors; // level color referece need to be renamed to be nodeColors
	std::vector<std::shared_ptr<Item>>& jewelers;  // jewelers reference 

	std::vector<int>& mMatchedNodes;

	/*removeMatchedNodes
	*/
	void removeMatchedNodes(); 
};

