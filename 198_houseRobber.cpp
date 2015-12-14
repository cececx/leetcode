// Sourse : https://leetcode.com/problems/house-robber/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, 
 * the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police.
 *
 **********************************************************************/
 
class Solution {
public:
	// 0ms, dp
    int rob(vector<int>& nums) {
        int pre = 0; // max profit if we robbed [i-2] house, so that we can rob [i] house.
        int cur = 0; // max profit if we robbed [i-1] house.
        for (int i=0; i<nums.size(); ++i) {
            int tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};