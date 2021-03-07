#pragma once
#include "Command.h"
#include <vector>
#include "Match3Graph.h"
#include <memory>
#include "JewelryItem.h"
class FillCommand :
    public Command
{
public:
	FillCommand(std::vector<int>& mlevelColors, std::vector<std::shared_ptr<Item>>& jewelers, std::shared_ptr<Match3Graph>& match3Graph):
		mlevelColors(mlevelColors), jewelers(jewelers), mMatch3Graph(match3Graph)
	{

	}

	~FillCommand() {

	}

public:
	void execute();
	bool isFinished();


private:
	bool mCompleted; // is animation completed
	std::shared_ptr<Match3Graph>& mMatch3Graph; // match3 algorthim reference 

	std::vector<int>& mlevelColors; // level color referece need to be renamed to be nodeColors
	std::vector<std::shared_ptr<Item>>& jewelers;  // jewelers reference 

	/*fill
	* fill all marked nodes as removed with new jewerls
	*/
	void fill(); // 
};

