#include "gtest/gtest.h"
#include "../msvc/CommandManager.cpp"
#include "../msvc/TestCommand.cpp"
TEST(CommandQueueTest, WhenAddNewCommandQueueSizeShouldbe1) {

	CommandManager commandManager;



	commandManager.addCommand(std::make_shared<TestCommand>());

	EXPECT_EQ(commandManager.size(), 1);


}


TEST(CommandQueueTest, WhenExecuteCommandQueueSizeShouldbe0) {

	CommandManager commandManager;

	std::shared_ptr<TestCommand>  test =  std::make_shared<TestCommand>();

	commandManager.addCommand(test);
	test->execute();
	commandManager.update();
	EXPECT_EQ(commandManager.size(), 0);
}