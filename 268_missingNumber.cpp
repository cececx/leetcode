// Sourse : https://leetcode.com/problems/missing-number/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
 * find the one that is missing from the array.
 *
 * Note:
 * Solve it with O(n) time and O(1) space
 *
 **********************************************************************/
 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        int size = nums.size();
        for (int i=0; i<size; ++i) {
            ret ^= nums[i];
            ret ^= i+1;
        }
        return ret;
    }
};