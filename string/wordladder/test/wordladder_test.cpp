/*
 * wordladder_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */


#include "../src/wordladder.h"
#include "gtest/gtest.h"

TEST(testcase_OK1, wordladder)
{
	solution c;
	string beginWord = "hit";
	string endWord = "cog";
	unordered_set<string> wordDict = {"hot","dot","dog","lot","log"};

	int len = c.ladderLength(beginWord, endWord, wordDict);

	ASSERT_EQ(len, 5);
}

TEST(testcase_OK1, wordladder2)
{
	solution c;
	string beginWord = "a";
	string endWord = "a";
	unordered_set<string> wordDict = {"b"};

	int len = c.ladderLength(beginWord, endWord, wordDict);

	ASSERT_EQ(len, 1);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
