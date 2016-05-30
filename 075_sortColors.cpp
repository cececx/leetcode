// Sourse : https://leetcode.com/problems/sort-colors/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an array with n objects colored red, white or blue, 
 * sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 **********************************************************************/

class Solution {
public:
    // Time O(n), Space O(1). In place, one pass.
    void sortColors(vector<int>& nums) {
        int i = 0, a = 0, b = nums.size();       // a: end of color[0]. b: begin of color[2]
        while (i < b) {
            switch(nums[i]) {
            case 0: swap(nums[a++], nums[i++]); break;
            case 1: ++i; break;
            case 2: swap(nums[--b], nums[i]); break;
            }
        }
    }
};