// Sourse : https://leetcode.com/problems/wiggle-sort/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 * 
 * For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 * 
 **********************************************************************/
 
// 本宫也是个随随便便徒手greedy AC的人了
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++)
            if ((nums[i] < nums[i+1]) == (i&1))
                swap(nums[i], nums[i+1]);
    }
};