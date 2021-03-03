#include "Match3Graph.h"
#include <iostream>

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



void Match3Graph::testDfs(int nodeId, std::vector<bool>& hVisited, std::vector<bool>& vVisited, std::string& newstring, std::vector<std::vector<int>>& options) {

	newstring += ", " + std::to_string(nodeId);
	std::cout << nodeId << "\n";
	

	std::vector<int> possibleHorizonatlMatches;
	std::vector<int> possibleVerticalMatches;

	
	if (!hVisited[nodeId]) {
		for (int i = nodeId; i < GAME_ROW_MAX; i++)
		{

			hVisited[nodeId + i] = true;
		}
		hVisited[nodeId] = true;
	}
	
	if (!vVisited[nodeId]) {
		for (int j = nodeId; j < GAME_COL_MAX; j++)
		{

		}
		vVisited[nodeId] = true;
	}


	auto it = nodes->find(nodeId);
	if (it != nodes->end()) {
		std::set<int> neighbours = it->second;
		
		for each (int neighbour in neighbours)
		{
			if (!hVisited[neighbour] || !vVisited[neighbour]) {
				testDfs(neighbour, hVisited,vVisited, newstring, options);
			}

		}


	}


}

void Match3Graph::dfs(int nodeId)
{
	std::string log = "";
	std::vector<bool> vVisited(GAME_MAX_CELLS, false);
	std::vector<bool> HVisited(GAME_MAX_CELLS, false);

	std::vector<std::vector<int>> options;

	testDfs(nodeId, vVisited, HVisited, log, options);

	std::cout << "Finished" << "\n";


}

std::vector<int> * Match3Graph::findMatchesPoints(int nodeId)
{
	if (!nodeHasMoreRightNodes(nodeId))
		return nullptr;


	return nullptr;
}


bool Match3Graph::nodeHasMoreRightNodes(int nodeId)
{
	std::tuple<int, int> nodeLocation = findNodeLocationById(nodeId);
	int col = std::get<1>(nodeLocation);

	return col < GAME_ROW_MAX - 1;
}

bool Match3Graph::nodeHasMoreTopNodes(int nodeId)
{
	std::tuple<int, int> nodeLocation = findNodeLocationById(nodeId);
	int row = std::get<0>(nodeLocation);

	return row < GAME_ROW_MAX - 1;
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

	// connect right node
	if (col < GAME_ROW_MAX -1 ) {
		connectedEdges.insert(rightNodeId);
	}

	// connect top Node

	if (row < GAME_ROW_MAX - 1 && topNodeId < GAME_MAX_CELLS)
	{
		connectedEdges.insert(topNodeId);
	}

	// connect bottom Node
	if (row > 0 && bottomNodeId >= 0)
	{
		connectedEdges.insert(bottomNodeId);
	}


	// Connect with the leftNode
	if (col > 0 && leftNodeId >= 0) {
		connectedEdges.insert(leftNodeId);
	}



	nodes->insert(std::pair<int,std::set<int>>(nodeId, std::move(connectedEdges)));

}


