/*
Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], return ["2", "4->49", "51->74", "76->99"]
*/

#include "findmissingranges.h"

vector<string> findmissingranges::findMissingRanges(vector<int> &nums, int lower, int upper)
{
    if (nums.empty()) return {};

    int prev = lower - 1;
    int curr = 0;
    vector<string> res;
    for (int i = 0; i <= nums.size(); ++i) {
        curr = i == nums.size() ? upper + 1 : nums[i];   // upper + for convenience
        if (curr - prev > 1) {
            string tmp = "";
            if (curr - 1 == prev + 1) tmp = std::to_string(curr - 1);
            else tmp = std::to_string(prev + 1) + "->" + std::to_string(curr - 1);
            res.push_back(tmp);
        }
        prev = curr;
    }

    return res;
}

