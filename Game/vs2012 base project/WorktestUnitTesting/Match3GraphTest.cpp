//  Created by Youssef Hanna.
//  Copyright � 2021. All rights reserved.
//
#include "pch.h"
#include "../msvc/Match3Graph.cpp"
namespace GraphTests {

	class Match3GraphTest : public testing::Test {



	};


	TEST(Match3GraphTests, WhenCreateNewLevelShouldhas0Matches) {


		std::vector<int> colorNodes =
		{
		
			3,1,2,0,3,0,1,2,
			4,0,2,2,0,4,3,1,
			0,1,0,1,1,3,2,4,
			2,0,2,3,2,0,4,2,
			2,3,4,2,3,1,1,2,
			4,3,1,4,4,2,3,4,
			0,0,3,1,1,0,1,3,
			2,0,1,1,0,0,4,2,
			1,0,1,4,3,2,4,0,
			2,0,4,2,4,4,3,0,
			2,3,1,3,3,4,3,1,
			4,4,2,0,1,3,4,2,
			1,1,4,4,0,0,4,3,
			2,1,2,2,2,2,2,1,
			1,0,1,1,0,4,4,4,
			0,4,1,2,2,1,1,0
		};

		Match3Graph match3graph(colorNodes);


		for (uint32_t i = 0; i < GAME_MAX_CELLS; i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);


		std::vector<std::vector<int>>  matches = match3graph.findMatchedNodes(0);



		EXPECT_EQ(matches.size(), 0);
	
	}


	TEST(Match3GraphTests, WhenMarkedNodesIntheLastRowShouldbeStayed_Minus_1) {


	//	std::vector<JewelryItem*> jewelersItems;
		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 ,  4  ,  5 ,  6 ,  7 ,
			  8 ,  9 ,  10,  11 , 12 , 13 , 14 ,  15 ,
			 16 , 17 ,  18 , 19 , 20 , 21 , 22 , 23 ,
			 24 , 25 ,  26 , 27 ,  28 , 29 , 30 , 31 ,
			 32 , 33 ,  34 , 35 ,  36 , 37 , 38 , 39 ,
			 40 , 41 ,  42 , 43 , 44 , 45 , 46 , 47 ,
			 48 , 49 ,  50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 ,  58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);

		for (uint32_t i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
			
		//	jewelersItems.push_back(new JewelryItem(colorNodes[i],0,0,0,0));
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<int> removedNodes = { 56,57,58,59,60,61,62,63 };

		match3graph.removeMatchedNodes(removedNodes);

		match3graph.nodesGravityCheck(removedNodes);

		colorNodes = match3graph.getNodesColors();

		EXPECT_EQ(colorNodes[56], -1);
		EXPECT_EQ(colorNodes[57], -1);
		EXPECT_EQ(colorNodes[58], -1);
		EXPECT_EQ(colorNodes[59], -1);
		EXPECT_EQ(colorNodes[60], -1);
		EXPECT_EQ(colorNodes[61], -1);
		EXPECT_EQ(colorNodes[62], -1);
		EXPECT_EQ(colorNodes[63], -1);
	}

	TEST(Match3GraphTests, WhenMarkedNodesIntheFirstRowShouldbeLinkedtoTheTopNodes) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 ,  4  ,  5 ,  6 ,  7 ,
			  8 ,  9 ,  10,  11 , 12 , 13 , 14 ,  15 ,
			 16 , 17 ,  18 , 19 , 20 , 21 , 22 , 23 ,
			 24 , 25 ,  26 , 27 ,  28 , 29 , 30 , 31 ,
			 32 , 33 ,  34 , 35 ,  36 , 37 , 38 , 39 ,
			 40 , 41 ,  42 , 43 , 44 , 45 , 46 , 47 ,
			 48 , 49 ,  50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 ,  58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);
		for (uint32_t i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<int> removedNodes = { 0,1,2,3,4,5,6,7 };

		match3graph.removeMatchedNodes(removedNodes);

		match3graph.nodesGravityCheck(removedNodes);

		colorNodes = match3graph.getNodesColors();

		EXPECT_EQ(colorNodes[0], 8);
		EXPECT_EQ(colorNodes[1], 9);
		EXPECT_EQ(colorNodes[2], 10);
		EXPECT_EQ(colorNodes[3], 11);
		EXPECT_EQ(colorNodes[4], 12);
		EXPECT_EQ(colorNodes[5], 13);
		EXPECT_EQ(colorNodes[6], 14);
		EXPECT_EQ(colorNodes[7], 15);
	}
	TEST(Match3GraphTests, WhenMarkedNodesIntheSameRowShouldbeLinkedtoTheTopNodes) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 ,  4  ,  5 ,  6 ,  7 ,
			  8 ,  9 ,  10,  11 , 12 , 13 , 14 ,  15 ,
			 16 , 17 ,  18 , 19 , 20 , 21 , 22 , 23 ,
			 24 , 25 ,  26 , 27 ,  28 , 29 , 30 , 31 ,
			 32 , 33 ,  34 , 35 ,  36 , 37 , 38 , 39 ,
			 40 , 41 ,  42 , 43 , 44 , 45 , 46 , 47 ,
			 48 , 49 ,  50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 ,  58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);

		for (uint32_t i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<int> removedNodes = { 17,18,19,20,21 };

		match3graph.removeMatchedNodes(removedNodes);

		match3graph.nodesGravityCheck(removedNodes);

		colorNodes = match3graph.getNodesColors();

		EXPECT_EQ(colorNodes[17], 25);
		EXPECT_EQ(colorNodes[18], 26);
		EXPECT_EQ(colorNodes[19], 27);
		EXPECT_EQ(colorNodes[20], 28);
		EXPECT_EQ(colorNodes[21], 29);
	}
	TEST(Match3GraphTests, WhenMarkedNodesShouldbeLinkedtoTheTopNodes) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 ,  4  ,  5 ,  6 ,  7 ,
			  8 ,  9 ,  10,  11 , 12 , 13 , 14 ,  15 ,
			 16 , 17 ,  18 , 19 , 20 , 21 , 22 , 23 ,
			 24 , 25 ,  26 , 27 ,  28 , 29 , 30 , 31 ,
			 32 , 33 ,  34 , 35 ,  36 , 37 , 38 , 39 ,
			 40 , 41 ,  42 , 43 , 44 , 45 , 46 , 47 ,
			 48 , 49 ,  50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 ,  58 , 59 , 60 , 61 , 62 , 63
		};
		Match3Graph match3graph(colorNodes);

		for (uint32_t i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);
				
		std::vector<int> removedNodes = { 1,9,17 };

		match3graph.removeMatchedNodes(removedNodes);

		match3graph.nodesGravityCheck(removedNodes);

		colorNodes = match3graph.getNodesColors();

		EXPECT_EQ(colorNodes[1], 25);
		EXPECT_EQ(colorNodes[9], 33);
		EXPECT_EQ(colorNodes[17], 41);
	}

	TEST(Match3GraphTests, WhenSwapTwoNodesAndNoForMatchingShouldRollBack) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 ,  10, 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 ,  18 , 19 , 20 , 21 , 22 , 23 ,
			 24 , 25 ,  26 , 27 ,  28 , 29 , 30 , 31 ,
			 32 , 33 ,  34 , 35 ,  36 , 37 , 38 , 39 ,
			 40 , 41 ,  42 , 43 , 44 , 45 , 46 , 47 ,
			 48 , 49 ,  50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 ,  58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);


		for (uint32_t i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		int fNode = colorNodes[34];
		int sNode = colorNodes[26];
		match3graph.swapNodes(34, 26);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);


		EXPECT_EQ(colorNodes[34], fNode);
		EXPECT_EQ(colorNodes[26], sNode);

	}

	TEST(Match3GraphTests, WhenSwapTwoNodesVerticallyForMatchingShouldReturn_1_Matched) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 ,  10, 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 ,  5 , 19 , 20 , 21 , 22 , 23 ,
			 24 ,  5 ,  0 , 5 ,  28 , 29 , 30 , 31 ,
			 32 , 33 ,  5 , 0 ,  36 , 37 , 38 , 39 ,
			 40 , 41 , 42 ,	43 , 44 , 45 , 46 , 47 ,
			 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);


		for (unsigned int i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		match3graph.swapNodes(34, 26);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);


		EXPECT_EQ(matchedVector.size(), 1);
		EXPECT_EQ(matchedVector[0].size(), 3);

	}


	TEST(Match3GraphTests, WhenSwapTwoNodesForMatchingShouldReturn_1_Matched) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 ,  5 , 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 ,  5 , 19 , 20 , 21 , 22 , 23 ,
			 24 , 25 ,  0 ,/**/ 5 ,  28 , 29 , 30 , 31 ,
			 32 , 33 ,  5 , 0 ,  36 , 37 , 38 , 39 ,
			 40 , 41 , 42 ,	43 , 44 , 45 , 46 , 47 ,
			 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);


		for (unsigned int i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		match3graph.swapNodes(26, 27);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);


		EXPECT_EQ(matchedVector.size(), 1);
		EXPECT_EQ(matchedVector[0].size(), 4);

	}

	TEST(Match3GraphTests, WhenSendingLevelwith_MatchedBeginEndMiddle_MatchPossiblityShouldRetrun4) {


		std::vector<int> colorNodes =
		{
			  6 ,  6  ,  6 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 , 10 , 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 , /**/ 5 , /**/5 ,/**/ 5 , 21 , 22 , 23 ,
			 24 , 25 ,/**/  5 , /**/0 , 28 , 29 , 30 , 31 ,
			 32 , 33 , /**/ 5 , /**/0 , 36 , 37 , 38 , 39 ,
			 40 , 41 , 42 ,	43 , 44 , 45 , 46 , 47 ,
			 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 , 58 , 59 , 60 , 0 , 0 , 0
		};

		Match3Graph match3graph(colorNodes);


		for (unsigned int i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);



		EXPECT_EQ(matchedVector.size(), 4);


	}

	TEST(Match3GraphTests, WhenSendingLevelwith_MatchedMiddleAndEnd_MatchPossiblityShouldRetrun3) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 , 10 , 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 , /**/ 5 , /**/5 ,/**/ 5 , 21 , 22 , 23 ,
			 24 , 25 ,/**/  5 , /**/0 , 28 , 29 , 30 , 31 ,
			 32 , 33 , /**/ 5 , /**/0 , 36 , 37 , 38 , 39 ,
			 40 , 41 , 42 ,	43 , 44 , 45 , 46 , 47 ,
			 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 , 58 , 59 , 60 , 0 , 0 , 0
		};

		Match3Graph match3graph(colorNodes);


		for (unsigned i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);



		EXPECT_EQ(matchedVector.size(), 3);


	}

	TEST(Match3GraphTests, WhenSendingLevelwith_CommonMatchedPoint_MatchPossiblityShouldRetrun2) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 , 10 , 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 , /**/ 5 , /**/5 ,/**/ 5 , 21 , 22 , 23 ,
			 24 , 25 ,/**/  5 , /**/0 , 28 , 29 , 30 , 31 ,
			 32 , 33 , /**/ 5 , /**/0 , 36 , 37 , 38 , 39 ,
			 40 , 41 , 42 ,	43 , 44 , 45 , 46 , 47 ,
			 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);


		for (unsigned i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);

		std::vector<int> flattenVector;


		EXPECT_EQ(matchedVector.size(), 2);


	}

	TEST(Match3GraphTests, WhenSendingLevelwith_2_MatchPossiblityShouldRetrun2) {


		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 , 10 , 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 , /**/ 5 , /**/2 , 20 , 21 , 22 , 23 ,
			 24 , 25 ,/**/  5 , /**/2 , 28 , 29 , 30 , 31 ,
			 32 , 33 , /**/ 5 , /**/2 , 36 , 37 , 38 , 39 ,
			 40 , 41 , 42 ,	43 , 44 , 45 , 46 , 47 ,
			 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);


		for (unsigned i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);

		std::vector<int> flattenVector;

	
		EXPECT_EQ(matchedVector.size(), 2);


	}

	TEST(Match3GraphTests, WhenSendingLevelwith_1_MatchPossiblityShouldRetrun1) {

		

		std::vector<int> colorNodes =
		{
			  0 ,  1 ,  2 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 , 10 , 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 , /**/ 5 , 19 , 20 , 21 , 22 , 23 ,
			 24 , 25 ,/**/  5 , 27 , 28 , 29 , 30 , 31 ,
			 32 , 33 , /**/ 5 , 35 , 36 , 37 , 38 , 39 ,
			 40 , 41 , 42 ,	43 , 44 , 45 , 46 , 47 ,
			 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);


		for (unsigned i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);


		EXPECT_EQ(matchedVector.size(), 1);
		EXPECT_NE(std::find(matchedVector[0].begin(), matchedVector[0].end(),18), matchedVector[0].end());
		EXPECT_NE(std::find(matchedVector[0].begin(), matchedVector[0].end(), 26), matchedVector[0].end());
		EXPECT_NE(std::find(matchedVector[0].begin(), matchedVector[0].end(), 34), matchedVector[0].end());

	}


	TEST(Match3GraphTests, WhenSendingLevelwith_AllMatched_MatchPossiblityShouldReturnNonRpeatedMatched) {


		std::vector<int> colorNodes =
		{
			0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
			0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
			0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
			0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
			0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
			0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
			0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
			0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
		};

		Match3Graph match3graph(colorNodes);

		for (unsigned i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<std::vector<int>> matchedVector = match3graph.findMatchedNodes(0);

		int matchedSize = matchedVector.size();
		
		EXPECT_LE(matchedSize, 50);

	}
	TEST(Match3GraphTests, WhenSendingLevelwith_No_MatchPossiblityShouldRetrun0) {


		std::vector<int> colorNodes = 
		{
			  0 ,  1 ,  2 ,  3 , 4  ,  5 ,  6 ,  7 ,
			  8 ,  9 , 10 , 11 , 12 , 13 , 14 ,	15 ,
			 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 ,
			 24 , 25 , 26 , 27 , 28 , 29 , 30 , 31 ,
			 32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 
			 40 , 41 , 42 ,	43 , 44 , 45 , 46 , 47 ,
			 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
			 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63
		};

		Match3Graph match3graph(colorNodes);

		for (unsigned i = 0; i < colorNodes.size(); i++) {
			match3graph.addNode(colorNodes[i], i);
		}

		match3graph.setNodesColors(colorNodes);

		std::vector<std::vector<int >> matchedVector = match3graph.findMatchedNodes(0);

		
		EXPECT_EQ(matchedVector.size(), 0);

	}
	TEST(Match3GraphTests, WhenNodeId_0_MAXNodeNumberInRowShouldbe_7) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		EXPECT_EQ(match3graph.calculateMaxNodeIdPerRow(0),7);

	}

	TEST(Match3GraphTests, WhenNodeId_11_MAXNodeNumberInRowShouldbe_15) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		EXPECT_EQ(match3graph.calculateMaxNodeIdPerRow(11), 15);

	}

	TEST(Match3GraphTests, WhenNodeId_35_MAXNodeNumberInRowShouldbe_39) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		EXPECT_EQ(match3graph.calculateMaxNodeIdPerRow(35), 39);

	}

	TEST(Match3GraphTests, WhenNodeId_0_MAXNodeNumberInColShouldbe_56) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		EXPECT_EQ(match3graph.calculateMaxNodeIdPerCol(0), 56);

	}

	TEST(Match3GraphTests, WhenNodeId_35_MAXNodeNumberInColShouldbe_59) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		EXPECT_EQ(match3graph.calculateMaxNodeIdPerCol(35), 59);

	}

	TEST(Match3GraphTests, WhenNodeId_23_MAXNodeNumberInColShouldbe_63) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		EXPECT_EQ(match3graph.calculateMaxNodeIdPerCol(23), 63);

	}




	TEST(Match3GraphTests, WhenNodeIdLessThan55ShouldhasTopNode) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		for (int i = 0; i < GAME_MAX_CELLS - GAME_COL_MAX; i++) {

			EXPECT_TRUE(match3graph.nodeHasMoreTopNodes(i));
		}

	}


	TEST(Match3GraphTests, WhenNodeNotLocatedInLastColsholdHasRightNode) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		for (int i = 0; i < GAME_MAX_CELLS ; i++) {
			int col = i % GAME_COL_MAX;
			if (col < GAME_ROW_MAX - 1) {
				EXPECT_TRUE(match3graph.nodeHasMoreRightNodes(i));
			}
			else {
				EXPECT_FALSE(match3graph.nodeHasMoreRightNodes(i));
			}
			
		}
	}



	TEST(Match3GraphTests, WhenConstructGraphWithMoreThan64VectorShouldIgnoreit) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);

		for (int i = 0; i < 100; i++) {

			match3graph.addNode(0, i);
		}
		

		auto map = match3graph.getNodes();

		auto it = map->find(6);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 64);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 3);
		EXPECT_NE(edges.find(5), edges.end());
		EXPECT_NE(edges.find(7), edges.end());
		EXPECT_NE(edges.find(14), edges.end());

	}


	TEST(Match3GraphTests, WhenAddNodeNegativeNodeIdMapSizeShouldbe0) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, -1);

		EXPECT_EQ(match3graph.getNodes()->size(), 0);

	}

	TEST(Match3GraphTests, WhenAddNode_64_NodeIdMapSizeShouldbe0) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 64);

		EXPECT_EQ(match3graph.getNodes()->size(), 0);

	}

	TEST(Match3GraphTests, WhenAddNode0MapShouldHas2Edges1AND8) {
	
		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0,0);
		auto map = match3graph.getNodes();
		auto it = map->find(0);
	
		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 2);
		EXPECT_NE(edges.find(1), edges.end()); // fix failing 
		EXPECT_NE(edges.find(8), edges.end()); // fix failing

	}


	TEST(Match3GraphTests, WhenAddNode1MapShouldHas3Edges0_2_9) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 1);
		auto map = match3graph.getNodes();
		auto it = map->find(1);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 3);
		EXPECT_NE(edges.find(2), edges.end()); 
		EXPECT_NE(edges.find(0), edges.end()); 
		EXPECT_NE(edges.find(9), edges.end()); 

	}


	TEST(Match3GraphTests, WhenAddNode2MapShouldHas3Edges1_3_10) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 2);
		auto map = match3graph.getNodes();
		auto it = map->find(2);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 3);
		EXPECT_NE(edges.find(1), edges.end());
		EXPECT_NE(edges.find(3), edges.end());
		EXPECT_NE(edges.find(10), edges.end());

	}


	TEST(Match3GraphTests, WhenAddNode_6_MapShouldHas3Edges5_7_13) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 6);
		auto map = match3graph.getNodes();

		auto it = map->find(6);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 3);
		EXPECT_NE(edges.find(5), edges.end());
		EXPECT_NE(edges.find(7), edges.end());
		EXPECT_NE(edges.find(14), edges.end());

	}


	TEST(Match3GraphTests, WhenAddNode_22_MapShouldHas_4_Edges21_14_23_30) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 22);
		auto map = match3graph.getNodes();

		auto it = map->find(22);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(),1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 4);
		EXPECT_NE(edges.find(21), edges.end());
		EXPECT_NE(edges.find(14), edges.end());
		EXPECT_NE(edges.find(23), edges.end());
		EXPECT_NE(edges.find(30), edges.end());

	}


	TEST(Match3GraphTests, WhenAddNode_37_MapShouldHas_4_Edges36_38_45_29) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 37);
		auto map = match3graph.getNodes();

		auto it = map->find(37);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 4);
		EXPECT_NE(edges.find(36), edges.end());
		EXPECT_NE(edges.find(38), edges.end());
		EXPECT_NE(edges.find(45), edges.end());
		EXPECT_NE(edges.find(29), edges.end());

	}


	TEST(Match3GraphTests, WhenAddNode_24_MapShouldHas_3_Edges25_16_32) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 24);
		auto map = match3graph.getNodes();

		auto it = map->find(24);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 3);
		EXPECT_NE(edges.find(25), edges.end());
		EXPECT_NE(edges.find(16), edges.end());
		EXPECT_NE(edges.find(32), edges.end());

	}


	TEST(Match3GraphTests, WhenAddNode_56_MapShouldHas_3_Edges25_16_32) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 56);
		auto map = match3graph.getNodes();

		auto it = map->find(56);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 2);
		EXPECT_NE(edges.find(57), edges.end());
		EXPECT_NE(edges.find(48), edges.end());

	}


	TEST(Match3GraphTests, WhenAddNode_63_MapShouldHas_3_Edges25_16_32) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 63);
		auto map = match3graph.getNodes();

		auto it = map->find(63);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 2);
		EXPECT_NE(edges.find(55), edges.end());
		EXPECT_NE(edges.find(62), edges.end());

	}

	TEST(Match3GraphTests, WhenAddNode_7_MapShouldHas3Edges6_15) {

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		match3graph.addNode(0, 7);
		auto map = match3graph.getNodes();
		auto it = map->find(7);

		std::set<int> edges = it->second;


		EXPECT_EQ(map->size(), 1);
		EXPECT_NE(it, map->end());

		EXPECT_EQ(edges.size(), 2);
		EXPECT_NE(edges.find(6), edges.end());
		EXPECT_NE(edges.find(15), edges.end());

	}


	TEST(Match3GraphTests, WhenSendingNodeWithId0ShouldRetrunTupleWith_0_0) {

		//std::map<int, std::set<int>> n;
		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		std::tuple<int, int> location = match3graph.findNodeLocationById(0);


		EXPECT_EQ(std::get<0>(location), 0);
		EXPECT_EQ(std::get<1>(location), 0);

	}


	TEST(Match3GraphTests, WhenSendingNodeWithId9ShouldRetrunTupleWith_1_1) {

		//std::map<int, std::set<int>> n;

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		std::tuple<int, int> location = match3graph.findNodeLocationById(9);


		EXPECT_EQ(std::get<0>(location), 1);
		EXPECT_EQ(std::get<1>(location), 1);

	}

	TEST(Match3GraphTests, WhenSendingNodeWithId19ShouldRetrunTupleWith_2_3) {

		//std::map<int, std::set<int>> n;

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		std::tuple<int, int> location = match3graph.findNodeLocationById(19);


		EXPECT_EQ(std::get<0>(location), 2);
		EXPECT_EQ(std::get<1>(location), 3);

	}


	TEST(Match3GraphTests, WhenSendingNodeWithId28ShouldRetrunTupleWith_3_4) {

		//std::map<int, std::set<int>> n;

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		std::tuple<int, int> location = match3graph.findNodeLocationById(28);


		EXPECT_EQ(std::get<0>(location), 3);
		EXPECT_EQ(std::get<1>(location), 4);

	}



	TEST(Match3GraphTests, WhenSendingNodeWithId37ShouldRetrunTupleWith_4_5) {

		//std::map<int, std::set<int>> n;

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		std::tuple<int, int> location = match3graph.findNodeLocationById(37);


		EXPECT_EQ(std::get<0>(location), 4);
		EXPECT_EQ(std::get<1>(location), 5);

	}


	TEST(Match3GraphTests, WhenSendingNodeWithId46ShouldRetrunTupleWith_5_6) {

		//std::map<int, std::set<int>> n;

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		std::tuple<int, int> location = match3graph.findNodeLocationById(46);


		EXPECT_EQ(std::get<0>(location), 5);
		EXPECT_EQ(std::get<1>(location), 6);

	}

	TEST(Match3GraphTests, WhenSendingNodeWithId54ShouldRetrunTupleWith_6_6) {

		//std::map<int, std::set<int>> n;

		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		std::tuple<int, int> location = match3graph.findNodeLocationById(54);


		EXPECT_EQ(std::get<0>(location), 6);
		EXPECT_EQ(std::get<1>(location), 6);

	}


	TEST(Match3GraphTests, WhenSendingNodeWithId63ShouldRetrunTupleWith_7_7) {

		
		std::vector<int> colorNodes;
		Match3Graph match3graph(colorNodes);
		std::tuple<int, int> location = match3graph.findNodeLocationById(63);


		EXPECT_EQ(std::get<0>(location), 7);
		EXPECT_EQ(std::get<1>(location), 7);

	}


}

