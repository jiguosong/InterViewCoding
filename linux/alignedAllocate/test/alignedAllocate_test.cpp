/*
 * alignedAllocate_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "../src/alignedAllocate.h"

#include <iostream>

using std::cout;
using std::endl;

TEST(testcase_OK1, alignedAllocate)
{
    alignedAllocate_test c;

    size_t sizeInBytes = 1999;
    size_t alignment = 32;

    int *p = (int *) c.alignedAllocate(sizeInBytes, alignment);
    ASSERT_EQ((int) p % alignment, 0);
    printf("%p\n\n", p);
    c.alignned_free(p);
    p = nullptr;
}

TEST(testcase_OK1, alignedAllocate2)
{
    alignedAllocate_test c;

    size_t sizeInBytes = 1999;
    size_t alignment = 32;

    int *p = (int *) c.alignedAllocate2(sizeInBytes, alignment);
    printf("%p\n", p);
    ASSERT_EQ((int) p % alignment, 0);

    c.alignned_free2(p);
    p = nullptr;
}

GTEST_API_ int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


