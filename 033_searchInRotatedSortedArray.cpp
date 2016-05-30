// Sourse : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Difficulty : Hard

/***********************************************************************
 *
 * A sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search.
 * If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 **********************************************************************/

class Solution {
public:

    // if ans is at right of m
    // ----------- rot -- m - ans --  :  n[0] > n[m], n[0] > T, n[m] < T
    // ----- m --- rot ---- ans ----  :  n[0] < n[m], n[0] > T, n[m] > T 
    // - m - ans - rot -------------  :  n[0] < n[m], n[0] < T, n[m] < T
    
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int mid = (l + r) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l] == target ? l : -1;
    }
};