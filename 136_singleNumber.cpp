// Sourse : https://leetcode.com/problems/single-number/
// Difficulty : Easy

/***********************************************************************
 *
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Require Time O(n), Space O(1)
 * 
 **********************************************************************/
 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int n : nums) ret ^= n;
        return ret;
    }
};