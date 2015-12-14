// Sourse : https://leetcode.com/problems/search-for-a-range/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Given a sorted array of integers, find the starting and ending position of a given target value. 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 **********************************************************************/
 
class Solution {
public:
	// 12ms, binary search for lower bound
    vector<int> searchRange(vector<int>& nums, int target) {
        int index1 = lower_bound (nums, target);
        int index2 = lower_bound (nums, target+1) - 1;
        if (nums[index1]==target && index2<nums.size())
            return {index1, index2};
        return {-1, -1};
    }
    
    int lower_bound (vector<int> nums, int target) {
        int L = 0, R = nums.size()-1;
        while (L <= R) {
            int mid = (L+R)>>1;
            if (nums[mid] < target) L = mid + 1;
            else R = mid - 1;
        }
        return L;
    }
};