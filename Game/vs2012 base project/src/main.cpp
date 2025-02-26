#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include <stdlib.h>
#include <crtdbg.h> 
#include "../msvc/LevelScene.h"

int main(int argc, char *argv[]) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // memeory Leak detection

	LevelScene game;
	game.Start();
	_CrtDumpMemoryLeaks();
	return 0;
}


