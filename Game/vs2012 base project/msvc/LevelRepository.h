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
	static std::vector<int> findLevelById(int levelId);

};

