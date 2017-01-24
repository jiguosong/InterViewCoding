/*
Program to return the index of the maximum number in the array [ To Note : the array may or may not contain multiple copies of maximum number ] such that each index ( which contains the maximum numbers ) have the probability of 1/no of max numbers to be returned.

Examples:

    [-1 3 2 3 3], each of positions [1,3,4] have the probability 1/3 to be returned (the three 3s)
    [ 2 4 6 6 3 1 6 6 ], each of [2,3,6,7] have the probability of 1/4 to be returned (corresponding to the position of the 6s).


 http://stackoverflow.com/questions/21717449/sample-an-index-of-a-maximal-number-in-an-array-with-a-probability-of-1-number
*/

#include <ctime>
#include <iostream>
#include "reservior_equalprobmax.h"

int reservior_equalprobmax::FindMaxIndex(vector<int> &nums)
{
    if (nums.empty()) return 0;
    int maxItem = nums[0];
    int count = 0;


    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > maxItem) {
            maxItem = nums[i];
            count = 0;
        }

        if (nums[i] == maxItem) {
            ++count;
            double randn = ((double) rand() / (RAND_MAX));
            if (randn < 1 / (double) count) {
                return i;
            }
        }
    }

    return 0;
}

//
//int reservior_equalprobmax::FindMaxIndex(vector<int> &nums)
//{
//    if (nums.empty()) return 0;
//
//    int maxItem = nums[0];
//    int maxCount = 1;
//    for (int i = 1; i < nums.size(); ++i) {
//        if (nums[i] > maxItem) {
//            maxItem = nums[i];
//            maxCount = 1;
//        } else if (nums[i] == maxItem) {
//            ++maxCount;
//        }
//    }
//
//    std::cout << maxItem << std::endl;
//    std::cout << maxCount << std::endl;
//
//    std::srand(std::time(0));
//    int occurance = rand() % maxCount + 1;
//    int cnt = 0;
//    int res = 0;
//    for (int i = 0; i < nums.size(); ++i) {
//        if (nums[i] == maxItem) {
//            cnt++;
//            if (cnt == occurance) {
//                res = i;
//                break;
//            };
//        }
//    }
//
//    return res;
//}
//
