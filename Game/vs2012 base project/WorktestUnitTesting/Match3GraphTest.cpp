#include "pch.h"
#include "../msvc/Match3Graph.cpp"
class Match3GraphTest : public testing::Test {



};

TEST(Match3GraphTests, WhenSendingNodeWithId0ShouldRetrunTupleWith_0_0) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int ,int> location = match3graph.findNodeLocationById(0);


  EXPECT_EQ(std::get<0>(location), 0);
  EXPECT_EQ(std::get<1>(location),0);

}


TEST(Match3GraphTests, WhenSendingNodeWithId9ShouldRetrunTupleWith_1_1) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int, int> location = match3graph.findNodeLocationById(9);


	EXPECT_EQ(std::get<0>(location), 1);
	EXPECT_EQ(std::get<1>(location), 1);

}

TEST(Match3GraphTests, WhenSendingNodeWithId19ShouldRetrunTupleWith_2_3) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int, int> location = match3graph.findNodeLocationById(19);


	EXPECT_EQ(std::get<0>(location), 2);
	EXPECT_EQ(std::get<1>(location), 3);

}


TEST(Match3GraphTests, WhenSendingNodeWithId28ShouldRetrunTupleWith_3_4) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int, int> location = match3graph.findNodeLocationById(28);


	EXPECT_EQ(std::get<0>(location), 3);
	EXPECT_EQ(std::get<1>(location), 4);

}



TEST(Match3GraphTests, WhenSendingNodeWithId37ShouldRetrunTupleWith_4_5) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int, int> location = match3graph.findNodeLocationById(37);


	EXPECT_EQ(std::get<0>(location), 4);
	EXPECT_EQ(std::get<1>(location), 5);

}


TEST(Match3GraphTests, WhenSendingNodeWithId46ShouldRetrunTupleWith_5_6) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int, int> location = match3graph.findNodeLocationById(46);


	EXPECT_EQ(std::get<0>(location), 5);
	EXPECT_EQ(std::get<1>(location), 6);

}

TEST(Match3GraphTests, WhenSendingNodeWithId54ShouldRetrunTupleWith_6_6) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int, int> location = match3graph.findNodeLocationById(54);


	EXPECT_EQ(std::get<0>(location), 6);
	EXPECT_EQ(std::get<1>(location), 6);

}


TEST(Match3GraphTests, WhenSendingNodeWithId63ShouldRetrunTupleWith_7_7) {

	std::map<int, std::set<int>> n;

	Match3Graph match3graph(n);
	std::tuple<int, int> location = match3graph.findNodeLocationById(63);


	EXPECT_EQ(std::get<0>(location), 7);
	EXPECT_EQ(std::get<1>(location), 7);

}

