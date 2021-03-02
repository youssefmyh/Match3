#include "Match3Graph.h"

void Match3Graph::addNode(int color, int row,int col)
{
	
}

std::tuple<int, int> Match3Graph::findNodeLocationById(int nodeId)
{
	// Find Node Col by dividing (NodeId / Max )
	int col = nodeId % GAME_COL_MAX;
	int row = floor( nodeId/ GAME_COL_MAX);

	return std::move(std::tuple<int, int>(col,row));
}

bool Match3Graph::test()
{
	return false;
}
