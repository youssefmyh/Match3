#include "CommandManager.h"

void CommandManager::addCommand(Command *command)
{
	m_commandsQueue.push(command);

}


void CommandManager::update()
{

	if (m_commandsQueue.size() <= 0)
		return;

	mCurrentCommand = m_commandsQueue.front();

	if (mCurrentCommand != nullptr && mCurrentCommand->isFinished()){
		m_commandsQueue.pop();
		delete mCurrentCommand;
		mCurrentCommand = nullptr;
	}

	
}
