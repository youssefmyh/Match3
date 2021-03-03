#pragma once
#include <set>
#include <map>
#include "Match3Settings.h"

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
	
	std::map<int, std::set<int>>* getNodes() const;


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




/*---------------------------------Private Variable Section----------------------------------------------------------------*/

private:
	std::map<int, std::set<int>> *nodes; //Adjacency list of Nodes


};

