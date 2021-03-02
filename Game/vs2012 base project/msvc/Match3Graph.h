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
public:
		
	Match3Graph(std::map<int, std::set<int>> n) :nodes(nodes) {}

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


private:
	std::map<int, std::set<int>> nodes;

};

