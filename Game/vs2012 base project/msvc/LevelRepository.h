#pragma once
/*
* Repositroy pattern 
* Get Level by ID
*/
#include <vector>
class LevelRepository
{
	/*
	* findLevelById 
	* @param levelId
	* Repository Pattern to Load Level by ID 
	*/
	std::vector<int> findLevelById(int levelId);

};

