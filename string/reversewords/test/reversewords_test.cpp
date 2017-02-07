#include "gtest/gtest.h"
#include "../src/reversewords.h"

TEST(testcase_OK, reverse_word)
{

	solution test;
	std::string s = "the sky is blue";
	test.reverseWords(s);
	EXPECT_EQ(s, "blue is sky the");
}

TEST(testcase_OK2, reverse_word)
{
	solution test;
	std::string s = "abc";
	test.reverseWords(s);
	EXPECT_EQ(s, "abc");
}

TEST(testcase_Empty, reverse_word)
{
	solution test;
	std::string s = "";
	test.reverseWords(s);
	EXPECT_EQ(s, "");
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


