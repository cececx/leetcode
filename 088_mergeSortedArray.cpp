// Sourse : https://leetcode.com/problems/merge-sorted-array/
// Difficulty : Easy

/***********************************************************************
 *
 * Given two sorted integer arrays nums1 and nums2, 
 * merge nums2 into nums1 as one sorted array.
 *
 **********************************************************************/

class Solution {
public:
    // Time O(n+m)
    // Since the last n items in array1 is empty, merge the arrays from back to front
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (i >= 0 && j >= 0)
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};