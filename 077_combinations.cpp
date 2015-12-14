// Sourse : https://leetcode.com/problems/combinations/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 *
 **********************************************************************/
 
class Solution {
public:
	// 12ms, backtracking
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        combine(ans, comb, k, n+1, 1);
        return ans;
    }
    
    void combine(vector<vector<int>>& ans, vector<int> comb, int remain, int n, int start) {
        if(!remain) {
            ans.push_back(comb);
            return;
        }
        for (int i = start; i <= n-remain; ++i) {
            comb.push_back(i);
            combine(ans, comb, remain-1, n, i+1);
            comb.pop_back();
        }
    }
};