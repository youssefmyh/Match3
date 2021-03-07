#include "RemoveMatchedCommand.h"

void RemoveMatchedCommand::execute()
{
	removeMatchedNodes();

}

void RemoveMatchedCommand::removeMatchedNodes() {

	
	for (unsigned int i = 0; i < mMatchedNodes.size(); i++) {

		mlevelColors[mMatchedNodes[i]] = -1; // Marked removed nodes to be -1 
		jewelers[mMatchedNodes[i]] = nullptr;
	}

	mCompleted = true;
	
}

bool RemoveMatchedCommand::isFinished()
{
	return mCompleted;
}