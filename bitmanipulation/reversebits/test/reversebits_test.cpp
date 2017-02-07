/*
 * reversebits_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include <bitset>
#include "gtest/gtest.h"
#include "../src/reversebits.h"

TEST(testcase_OK, revserse_bits)
{
    solution c;
    int x = 12345676;

    std::cout << "c = " << std::bitset<32>(x) << std::endl;
    uint32_t res = c.reverseBits(x);

    std::cout << "c = " << std::bitset<32>(res) << std::endl;

    EXPECT_EQ(x, c.reverseBits(res));
}

TEST(testcase_OK, revserse_bits2)
{
    solution c;
    unsigned char x = 200;

    std::cout << std::endl;
    std::cout << "c = " << std::bitset<8>(x) << std::endl;
    unsigned char res = c.reverseBits2(x);
    std::cout << "c = " << std::bitset<8>(res) << std::endl;

}
GTEST_API_ int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



