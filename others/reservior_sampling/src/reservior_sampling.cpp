/*
 http://massivealgorithms.blogspot.com/2014/06/reservoir-sampling-geeksforgeeks.html
 https://gregable.com/2007/10/reservoir-sampling.html
*/

#include <random>
#include <iostream>
#include "reservior_sampling.h"


static int getRandom(int lower, int upper)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(gen);
}

static float getRandomf(int lower, int upper)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(lower, upper);
    return dist(gen);
}

// nums could be a data stream
vector<int> reservior_sampling::SelectKfromNStream(vector<int> &nums, int k)
{
    if(nums.empty() || k <= 0) return {};
    if(k == nums.size()) return nums;

    vector<int> reservior(k, 0);
    int i;
    for (i = 0; i < k; ++i) {
        reservior[i] = nums[i];
    }

    for(; i < nums.size(); ++i) {
        int j = getRandom(0, i);
        if(j < k) reservior[j] = nums[i];
    }

    return reservior;
}

int reservior_sampling::SelectfromNStream(vector<int> &nums)
{
    if(nums.empty()) return -1;

    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(getRandomf(0, 1) < 1/(float)(i+1)) res = nums[i];
    }

    return res;
}



