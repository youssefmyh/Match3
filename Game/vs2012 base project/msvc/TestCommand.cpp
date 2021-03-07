#include "TestCommand.h"

void TestCommand::execute()
{
	mCompleted = true;
}

bool TestCommand::isFinished()
{
	return mCompleted;
}
