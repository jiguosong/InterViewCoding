/*
    https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
*/

#include "shuffle.h"

void shufflearray::ShuffleArray(vector<int> &nums)
{
    if (nums.empty()) return;

    int i = nums.size();
    std::srand(time(NULL));
    while (--i) {
        int j = std::rand() % (i + 1);
        std::swap(nums[i], nums[j]);
    }
}

