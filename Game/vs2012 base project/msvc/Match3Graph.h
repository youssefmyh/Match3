//  Created by Youssef Hanna.
//  Copyright © 2021. All rights reserved.
//
#pragma once
#include <set>
#include <map>
#include "Match3Settings.h"
#include <vector>
#include <string>
struct Match3Node {

	Match3Node(int id, std::set<int> &connectedNodes) : nodeId(id),adjacents(connectedNodes){}
	int nodeId;
	int color;
	std::set<int> adjacents;

};
class Match3Graph
{

/*---------------------------------Public Function Section----------------------------------------------------------------*/
public:
		
	Match3Graph() {
		nodes = new std::map<int, std::set<int>>();
		
		colord = 
		{
			0 , 0 , 0 , 1, 2, 3, 4 , 5,
			0 , 0 , 0 , 1, 2, 3, 4 , 5,
			0 , 0 , 0 , 1, 2, 3, 4 , 5,
			0 , 0 , 0 , 1, 2, 3, 4 , 5,
			0 , 0 , 0 , 1, 2, 3, 4 , 5,
			0 , 0 , 0 , 1, 2, 3, 4 , 5,
			0 , 0 , 0 , 1, 2, 3, 4 , 5,
			0 , 0 , 0 , 1, 2, 3, 4 , 5

		};
	}

	~Match3Graph() {
		
		auto it = nodes->begin();
		nodes->clear();
		delete nodes;
	}
	/*
	* Add Node to the Graph
	* @param int color
	* @param int row
	* @param int col
	*/
	void addNode(int color, int row,int col);


	/*
	* Add Node By Color and ID
	* @param int color
	* @param int nodeId
	*/
	void addNode(int color, int nodeId);
	/*
	* find Node Location By Id 
	* @param Node Id from 0 --> MAX_COL
	*/
	std::tuple<int, int> findNodeLocationById(int nodeId);
	
	/*
	* GgetNodeset 
	* Get the Graph Adjacency list 
	*/
	std::map<int, std::set<int>>* getNodes() const;


	/*
	* Calculate Max NodeId Per Row
	* Used to know how much you have to continue checking in specific row
	*/
	int calculateMaxNodeIdPerRow();

	/*
	* Calculate Max Node Id Per Col
	* Used to know how much you have to continue checking in specific Col
	*/
	int calculateMaxNodeIdPerCol();

	std::vector<int> * findMatchesPoints(int nodeId);

	/*
	/* Check if the node has more Right Nodes
	*/
	bool nodeHasMoreRightNodes(int nodeId);



	/*
	/* Check if the node has more Right Nodes
	*/
	bool nodeHasMoreTopNodes(int nodeId);
	void dfs(int nodeId);
/*---------------------------------Private Function Section----------------------------------------------------------------*/
private:
	/*
	* connectNodeById Every node should connect to 4 nodes 
	/*In case it's Located Row > 0 & Col <  MAX_COL(8) 
	* ----|---|-----
	* ----| Z |-----
	* ----|---|-----
	* @param int NodeId
	*/
	void connectNodeById(int nodeId);

	/*
	* dfs 
	* Depth first search for the Graph
	*/
	



/*---------------------------------Private Variable Section----------------------------------------------------------------*/

private:
	std::map<int, std::set<int>> *nodes; //Adjacency list of Nodes
	std::vector<int> colord; // Ball List
	

	void Match3Graph::testDfs(int nodeId, std::vector<bool>& hVisited, std::vector<bool>& vVisited, std::string& newstring, std::vector<std::vector<int>> &options);
};

