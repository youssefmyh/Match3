#include "CommandManager.h"

std::mutex lock_;
void CommandManager::addCommand(Command *command)
{
	m_commandsQueue.push(command);

}


void CommandManager::update()
{
	std::unique_lock<std::mutex> lock(lock_);
	if (m_commandsQueue.size() <= 0)
		return;

	mCurrentCommand = m_commandsQueue.front();

	mCurrentCommand->execute();
	if (mCurrentCommand != nullptr && mCurrentCommand->isFinished()){
		m_commandsQueue.pop();
		delete mCurrentCommand;
		mCurrentCommand = nullptr;
	}
	

	lock.unlock();
	
}
