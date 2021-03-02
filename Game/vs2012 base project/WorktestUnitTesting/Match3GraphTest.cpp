#include "pch.h"
#include "../msvc/Match3Graph.cpp"
class Match3GraphTest : public testing::Test {



};

TEST(Match3GraphTests, WhenSendingNodeWithId0ShouldRetrunTupleWith) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int ,int> location = match3graph.findNodeLocationById(0);


  EXPECT_EQ(std::get<0>(location), 0);
  EXPECT_EQ(std::get<0>(location),0);

}