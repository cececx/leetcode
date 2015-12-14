// Sourse : https://leetcode.com/problems/search-insert-position/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 * 
 * Examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 **********************************************************************/
 
class Solution {
public:
    #define LIBRARY
    #ifndef LIBRARY
    
    // 8ms, binary search for lower bound
    int searchInsert(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (nums[mid] < target) L = mid + 1;
            else R = mid - 1;
        }
        return L;
    }
    
    #else
    
    // 8ms, using library
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};