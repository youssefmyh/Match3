#include "Match3Graph.h"

void Match3Graph::addNode(int color, int row,int col)
{
	
}

void Match3Graph::addNode(int color, int nodeId)
{
	if (nodeId < 0 || nodeId > (GAME_MAX_CELLS-1) ) return;

	auto it = nodes->find(nodeId);

	if (it != nodes->end()) {
		return;
	}
	connectNodeById(nodeId);
	

}

std::tuple<int, int> Match3Graph::findNodeLocationById(int nodeId)
{
	// Find Node Col by dividing (NodeId / Max_Col )
	int col = nodeId % GAME_COL_MAX;
	int row = floor( nodeId/ GAME_COL_MAX);

	return std::move(std::tuple<int, int>(row,col));
}

std::map<int, std::set<int>>* Match3Graph::getNodes() const
{
	return nodes;
}

void Match3Graph::connectNodeById(int nodeId)
{

	std::tuple<int, int> nodeLocation = findNodeLocationById(nodeId);

	int row = std::get<0>(nodeLocation);
	int col = std::get<1>(nodeLocation);

	
	int leftNodeId  = nodeId - 1;    // Get Left Node
	int rightNodeId = nodeId + 1;   // Get Right Node Location
	int topNodeId = nodeId + GAME_COL_MAX; // 8 in this case
	int bottomNodeId = nodeId - GAME_COL_MAX;  // 8

	std::set<int> connectedEdges;
	// Connect with the leftNode
	if (col > 0 && leftNodeId >= 0) {
		connectedEdges.insert(leftNodeId);
	}
	// connect right node
	if (col < GAME_ROW_MAX -1 ) {
		connectedEdges.insert(rightNodeId);
	}

	// connect bottom Node
	if (row > 0 && bottomNodeId >= 0)
	{
		connectedEdges.insert(bottomNodeId);
	}

	// connect top Node

	if (row < GAME_ROW_MAX -1  && topNodeId < GAME_MAX_CELLS)
	{
		connectedEdges.insert(topNodeId);
	}

	nodes->insert(std::pair<int,std::set<int>>(nodeId, std::move(connectedEdges)));

}

