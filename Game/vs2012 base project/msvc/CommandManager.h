#pragma once
#include <queue>
#include "Command.h"
#include <mutex>
class CommandManager
{

public:
	CommandManager(){}

	/*addCommand
	* push command to the queue
	* @param Command *command
	*/
	void addCommand(std::shared_ptr<Command> command);

	/*update
	*/
	void update();

	~CommandManager() {
	
		while (!m_commandsQueue.empty()) {
			std::shared_ptr<Command> cmd = m_commandsQueue.front();
			m_commandsQueue.pop();
		}
	
	}

private:
	std::queue<std::shared_ptr<Command>> m_commandsQueue; // command queue
	std::shared_ptr<Command> mCurrentCommand; // current command
  
};

