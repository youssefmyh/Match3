#pragma once
/*
* Repositroy pattern 
* Get Level by ID
*/
#include <vector>
class LevelRepository
{
public:
	/*
	* findLevelById 
	* @param levelId
	* Repository Pattern to Load Level by ID 
	*/
	// TODO: Level should be loaded from somewhere elese 
	static std::vector<int> findLevelById(int levelId);

};

