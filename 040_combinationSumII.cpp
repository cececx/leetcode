// Sourse : https://leetcode.com/problems/combination-sum-ii/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 *
 * Input: candidate set [10,1,2,7,6,1,5] and target 8, 
 * Output: [[1, 7], [1, 2, 5], [2, 6], [1, 1, 6]] 
 *
 **********************************************************************/
 
 class Solution {
public:
	// 12ms, backtracking
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort (candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        combine (ans, comb, candidates, target, 0);
        return ans;
    }
    
    void combine (vector<vector<int>>& ans, vector<int> comb, vector<int> nums, int target, int index) {
        if (!target) ans.push_back(comb);
        for (int i = index; i < nums.size() && nums[i] <= target; ++i) {
            if (target == nums[i] || target >= nums[i]*2) {
                comb.push_back(nums[i]);
                combine (ans, comb, nums, target-nums[i], i+1);
                comb.pop_back();
            }
            while (i+1<nums.size() && nums[i+1]==nums[i])
                ++i;
        }
    }
};