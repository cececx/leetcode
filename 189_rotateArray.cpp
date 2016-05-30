// Sourse : https://leetcode.com/problems/rotate-array/
// Difficulty : Easy

/***********************************************************************
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * input: array = [1,2,3,4,5,6,7], k = 3
 * output: [5,6,7,1,2,3,4]
 * 
 **********************************************************************/
 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.begin() + n);
        reverse(nums.begin(), nums.begin() + n);
    }
};