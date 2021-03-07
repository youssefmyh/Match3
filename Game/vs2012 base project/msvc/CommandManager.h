#pragma once
#include <queue>
#include "Command.h"
class CommandManager
{

public:
	CommandManager():mCurrentCommand(nullptr){}
	void addCommand(Command *command);

	void update();

	~CommandManager() {
	
		while (!m_commandsQueue.empty()) {
			Command* cmd = m_commandsQueue.front();
			m_commandsQueue.pop();
			delete cmd;
		}
		delete mCurrentCommand;
	
	}

private:
	std::queue<Command*> m_commandsQueue;
	Command* mCurrentCommand;
  
};

