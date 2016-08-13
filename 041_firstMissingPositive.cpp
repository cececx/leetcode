// Source: https://leetcode.com/problems/first-missing-positive/
// Difficulty: Hard

/***********************************************************************
 *
 * Given an unsorted integer array, find the first missing positive integer.
 *
 **********************************************************************/

/*

Naive solution: sort, then start traverse from 1. O(nlogn)

Optimize: use in-place bucket sort. O(n)
 * If all numbers fit requires, the numbers in [0, N-1] should be [1, N]
 * Thus, swap all number X to index X-1

*/

// Time O(n), Space O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // swap X to X-1
        int n = nums.size();
        for (int i = 0; i < n;) {
            int a = nums[i];
            if (a <= 0 || a > n || i == a - 1 || nums[a-1] == a) i++;
            else swap(nums[i], nums[a-1]);
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};