// Sourse : https://leetcode.com/problems/subsets-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 * Note: The solution set must not contain duplicate subsets.
 * 
 **********************************************************************/

// Note: solution set can't contain duplicate subsets, but a subset can contain duplicate numbers.
// Time O(2^n), Space O(2^n)
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int> cur, vector<int>& nums, int index, int n) {
        if (index >= n) {
            res.push_back(cur);
            return;
        }
        for (int i=index; i<n; i++) {
            // avoid starting with the same number
            if (i != index && nums[i-1] == nums[i])
                continue;
            cur.push_back(nums[i]);
            backtrack(res, cur, nums, i+1, n);
            cur.pop_back();
        }
        res.push_back(cur);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(res, vector<int>(), nums, 0, nums.size());
        return res;
    }
};
