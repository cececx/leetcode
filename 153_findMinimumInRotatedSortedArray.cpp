// Sourse : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Difficulty : Medium

/***********************************************************************
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Find the minimum element.
 * 
 **********************************************************************/
 
class Solution {
public:
    // O(logn)
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r]) r = mid;    // (L, M]
            else l = mid + 1;                    // (M, R]
        }
        return nums[l];
    }
};