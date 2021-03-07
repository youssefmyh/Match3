#include "SwapCommand.h"

void SwapCommand::execute()
{
	swapNodes(mFistNodeId, mSecondNodeId);

}

std::vector<std::vector<int>> SwapCommand::swapNodes(int first, int second) {

	int firstNode = mlevelColors[first];
	int secondNode = mlevelColors[second];


	std::shared_ptr<Item> firstItemNode = jewelers[first];
	std::shared_ptr<Item> secondItemNode = jewelers[second];


	mlevelColors[first] = secondNode;
	mlevelColors[second] = firstNode;

	jewelers[first] = secondItemNode;
	jewelers[second] = firstItemNode;


	std::vector<std::vector<int>> allOptions = mMatch3Graph->findMatchedNodes(0);

	if (allOptions.size() <= 0)
	{
		mlevelColors[first] = firstNode;
		mlevelColors[second] = secondNode;


		jewelers[first] = firstItemNode;
		jewelers[second] = secondItemNode;

	}

	


	mCompleted = true;
	return std::move(allOptions);

}

bool SwapCommand::isFinished()
{
    return mCompleted;
}
