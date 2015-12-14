// Sourse : https://leetcode.com/problems/jump-game/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 *
 **********************************************************************/
 
class Solution {
public:
	// 16ms, greedy
    bool canJump(vector<int>& nums) {
        int curStep = nums[0];
        for (int i=0; i<nums.size(); i++) {
            if(curStep < nums[i]) curStep = nums[i];
            if(curStep >= nums.size() - i - 1) return true;
            if(curStep == 0) return false;
            --curStep;
        }
    }
};