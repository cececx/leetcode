// Sourse : https://leetcode.com/problems/combination-sum/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Input: candidate set [2,3,6,7] and target 7, 
 * Output: [[7], [2, 2, 3]] 
 *
 **********************************************************************/
 
class Solution {
public:
	// 16ms, backtracking
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> solution;
        backtrack(ans, candidates, solution, target, 0);
        return ans;
    }
    
    void backtrack(vector<vector<int>>& ans, vector<int> nums, vector<int> solution, int target, int depth) {
        if(!target) {
            ans.push_back(solution);
            return;
        }
        for (int i = depth; i < nums.size() && target >= nums[i]; ++i) {
            if (target == nums[i] || target >= 2*nums[i]) {
                solution.push_back(nums[i]);
                backtrack(ans, nums, solution, target-nums[i], i);
                solution.pop_back();
            }
        }
    }
};