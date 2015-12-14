// Sourse : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * It doesn't matter what you leave beyond the new length.
 *
 **********************************************************************/
 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int cur = 0;
        for(int i = 1; i<nums.size(); i++){
            if (nums[i] != nums[cur])
                nums[++cur] = nums[i];
        }
        return cur+1;
    }
};