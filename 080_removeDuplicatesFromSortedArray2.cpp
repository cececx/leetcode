// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * Return the length of new array. It doesn't matter what you leave beyond the new length.
 *
 **********************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        for (int a : nums) 
            if (cur < 2 || a > nums[cur-2])
                nums[cur++] = a;
        return cur;
    }
};
