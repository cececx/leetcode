// Sourse : https://leetcode.com/problems/subsets/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 **********************************************************************/

// 1. Backtracking. Time O(2^n), Space O(2^n)
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int> cur, vector<int>& nums, int index, int n) {
        if (index >= n) {
            res.push_back(cur);
            return;
        }
        for (int i=index; i<n; i++) {
            cur.push_back(nums[i]);
            backtrack(res, cur, nums, i+1, n);
            cur.pop_back();
        }
        backtrack(res, cur, nums, n, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, vector<int>(), nums, 0, nums.size());
        return res;
    }
};


// 2. Bit. Time O(2^n), Space O(2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int m = nums.size(), n = 1 << m;
        vector<vector<int>> res(n);
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                if (i&(1<<j))
                    res[i].push_back(nums[j]);
        return res;
    }
};
