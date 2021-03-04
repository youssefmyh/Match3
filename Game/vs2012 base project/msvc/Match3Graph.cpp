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

int Match3Graph::calculateMaxNodeIdPerRow(int nodeId)
{
	std::tuple<int, int> nodeLocation = findNodeLocationById(nodeId);
	int row = std::get<0>(nodeLocation);

	return ((row+1) * GAME_ROW_MAX) -1; 
}


int Match3Graph::calculateMaxNodeIdPerCol(int nodeId)
{
	std::tuple<int, int> nodeLocation = findNodeLocationById(nodeId);
	int col = std::get<1>(nodeLocation);

	return GAME_MAX_CELLS - (GAME_COL_MAX - col);
}


void Match3Graph::dfsFindAllMatches(int nodeId, std::vector<bool>& hVisited, std::vector<bool>& vVisited, std::vector<std::vector<int>>& matched) {

	
	std::vector<int> possibleHorizonatlMatches; // Horizonatl matched vector
	std::vector<int> possibleVerticalMatches; // vertical matched vector
	
	/*---------------------------------- find all Horizonatl Points  ---------------------------------------------------------*/
	/*
	* ----|---|-----
	* ----| Z |-----
	* ----|---|-----
	*/
	if (!hVisited[nodeId]){

		int maxNodeIdInRow = calculateMaxNodeIdPerRow(nodeId);

		possibleHorizonatlMatches.push_back(nodeId);

		for (int i = nodeId + 1; i <= maxNodeIdInRow; i++){ 

			int lastAddNode = possibleHorizonatlMatches.at(possibleHorizonatlMatches.size() - 1);
			if (nodesColors[lastAddNode] == nodesColors[i]){

				possibleHorizonatlMatches.push_back(i);

			}else {
				break;
			}

		}
		if (possibleHorizonatlMatches.size() >= 3){

			for each (int visitedNode in possibleHorizonatlMatches)
			{
				hVisited[visitedNode] = true;
			}
			matched.push_back(std::move(possibleHorizonatlMatches));
		}
	
		hVisited[nodeId] = true;
	}



	/*---------------------------------- find all Vertical Matched ---------------------------------------------------------*/

	
	if (!vVisited[nodeId]) {

		int maxNodeIdInCol = calculateMaxNodeIdPerCol(nodeId);
		possibleVerticalMatches.push_back(nodeId);

		for (int j = nodeId + GAME_COL_MAX ; j <= maxNodeIdInCol; j = j + GAME_COL_MAX){

			int lastAddNode = possibleVerticalMatches.at(possibleVerticalMatches.size() - 1);
			if (nodesColors[lastAddNode] == nodesColors[j]) {

				possibleVerticalMatches.push_back(j);

			}
			else {
				break;
			}

		}


		if (possibleVerticalMatches.size() >= 3) {

			for each (int visitedNode in possibleVerticalMatches)
			{
				vVisited[visitedNode] = true;
			}

			matched.push_back(std::move(possibleVerticalMatches));
		}
		vVisited[nodeId] = true;
	}


	/*---------------------------------- Depth first Search -------------------------------------*/

	auto it = nodes->find(nodeId);
	if (it != nodes->end()) {
		std::set<int> neighbours = it->second;
		
		for each (int neighbour in neighbours)
		{
			/* Point need to be checked*/
			if (!hVisited[neighbour] || !vVisited[neighbour]) {
				dfsFindAllMatches(neighbour, hVisited,vVisited, matched);
			}

		}


	}


}

std::vector<std::vector<int>> Match3Graph::findMatchedNodes(int nodeId)
{
	std::vector<bool> vVisited(GAME_MAX_CELLS, false);
	std::vector<bool> HVisited(GAME_MAX_CELLS, false);

	std::vector<std::vector<int>> options;

	dfsFindAllMatches(nodeId, vVisited, HVisited, options);


	return std::move(options);
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


void Match3Graph::setNodesColors(std::vector<int>& levelNodes) {

	this->nodesColors = levelNodes;

}


std::vector<std::vector<int>> Match3Graph::swapNodes(int first, int second) {

	int firstNode = nodesColors[first];
	int secondNode = nodesColors[second];

	nodesColors[first] = secondNode;
	nodesColors[second] = firstNode;

	std::vector<std::vector<int>> allOptions = findMatchedNodes(0);

	if (allOptions.size() <= 0)
	{
		nodesColors[first] = firstNode;
		nodesColors[second] = secondNode;
	}

	return std::move(allOptions);

}