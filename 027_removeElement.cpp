// Sourse : https://leetcode.com/problems/remove-element/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 **********************************************************************/
 
class Solution {
public:
    // 4ms, O(n)
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            while(nums[i] == val && i<len)
                swap(nums[i], nums[--len]);
        }
        return len;
    }
};