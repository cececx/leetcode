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
    #define USE_LIBRARY
    #ifndef USE_LIBRARY
    
	// 12ms
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int m = nums.size()-1, n = nums.size()-1;
        while (m > 0 && nums[m-1] > nums[m]) --m;
        if (m > 0) {
            while (nums[n]<=nums[m-1]) --n;
            swap(nums[m-1], nums[n]);
        }
        reverse(nums.begin()+m, nums.end());
    }
    
    #else
    
	// 12ms, using library
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
    
    #endif
};