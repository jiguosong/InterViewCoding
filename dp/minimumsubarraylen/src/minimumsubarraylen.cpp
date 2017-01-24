/*
Given an array of n positive integers and a positive integer s, find the minimal length of a
subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

If you have figured out the O(n) solution, try coding another solution of
which the time complexity is O(n log n).
 */

#include "minimumsubarraylen.h"
#include <climits>

int minimumsubarraylen::minSubArrayLen(int s, vector<int>& nums)
{

	if (nums.empty())
		return 0;
	int sz = nums.size();

	int left = 0;
	int right = 0;

	int min = INT_MAX;
	int sum = 0;
	while (right < sz) {
		sum += nums[right];
		while (sum >= s && left <= right) {
			min = std::min(min, right - left + 1);
			sum -= nums[left++];
		}
		++right;
	}

	if(min == INT_MAX) return 0;
	else return min;
}
