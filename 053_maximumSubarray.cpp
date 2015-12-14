// Sourse : https://leetcode.com/problems/maximum-subarray/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 **********************************************************************/
 
class Solution {
public:
	// 8ms, simplified dp
    int maxSubArray(vector<int>& nums) {
        int sum = 0, curMax = nums[0];
        for(int i=1; i<nums.size(); i++) {
            sum = max(nums[i], sum+nums[i]); // the max subarray end with nums[i]
            curMax = max(sum, curMax);
        }
        return curMax;
    }
};