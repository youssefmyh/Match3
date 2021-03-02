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

	void addNode(int color, int row,int col);

	std::tuple<int, int> findNodeLocationById(int nodeId);

	virtual bool test() ;


private:
	std::map<int, std::set<int>> nodes;

};

