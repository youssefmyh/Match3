#include "Match3Graph.h"

void Match3Graph::addNode(int color, int row,int col)
{
	
}

void Match3Graph::addNode(int color, int nodeId)
{
	if (nodeId < 0 || nodeId > (GAME_MAX_CELLS-1) ) return;

	std::tuple<int, int> nodeLocation = findNodeLocationById(nodeId);

	int row = std::get<0>(nodeLocation);
	int col = std::get<1>(nodeLocation);


	auto it = nodes.find(nodeId);

	if (it != nodes.end()) {
	


	}
	

}

std::tuple<int, int> Match3Graph::findNodeLocationById(int nodeId)
{
	// Find Node Col by dividing (NodeId / Max_Col )
	int col = nodeId % GAME_COL_MAX;
	int row = floor( nodeId/ GAME_COL_MAX);

	return std::move(std::tuple<int, int>(row,col));
}

