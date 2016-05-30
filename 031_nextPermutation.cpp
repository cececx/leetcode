// Sourse : https://leetcode.com/problems/next-permutation/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 *
 **********************************************************************/
 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, j = i;
        while (i >= 1 && nums[i] <= nums[i-1]) --i;
        while (j > i && nums[j] <= nums[i-1]) --j;
        if (i >= 1) swap(nums[i-1], nums[j]);
        reverse(nums.begin()+i, nums.end());
    }
};