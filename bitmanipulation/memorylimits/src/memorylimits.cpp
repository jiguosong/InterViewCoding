/*
  Given an input file with four billion integers, provide an algorithm to generate an integer
  which is not contained in the file. Assume you have 1 GB memory. Follow up with what you
  would do if you have only 10 MB of memory.

  1GB = 8 billion bits. So, with those bits, we can map all 4 billion integers (actually,
  2147483648 non-negative integers). We'll use integer arrays a[1+N/32] because an integer has 32bits.
*/

#include "memorylimits.h"

#define SHIFT 5
#define BITSPERWORD 32
#define MASK 0x1F // 31

vector<int> memorylimits::generateInteger(vector<int> nums, int N)
{
    if (nums.empty()) return {};

    tmp_array.resize(1 + N / 32);

    for (int i = 0; i < N; ++i) {
        clearBit(i);
    }

    for(auto e: nums) setBit(e);

    std::vector<int> res;
    for (int i = 0; i < N; ++i) {
        if (!testBit(i)) res.push_back(i);
    }

    return res;
}

/* 1 << (i & MASK): left shift from 0 to 31, represents 2^i
   i >> SHIFT: array index
               0-31   a[0]
	       32-63  a[1]
               64-95  a[2]
               ...    ...
*/

//10: ....00000000 00000000 00000000 00000100 00000000
//16: ....00000000 00000000 00000001 00000000 00000000
//35: ....00001000 00000000 00000000 00000000 00000000
//          a[1]                a[0] ->

void memorylimits::setBit(int i)
{
    tmp_array[i >> SHIFT] |= (1 << (i & MASK));
}

void memorylimits::clearBit(int i)
{
    tmp_array[i >> SHIFT] &= ~(1 << (i & MASK));
}

int memorylimits::testBit(int i)
{
    return tmp_array[i >> SHIFT] & (1 << (i & MASK));
}

