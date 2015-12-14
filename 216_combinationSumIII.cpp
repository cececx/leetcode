// Sourse : https://leetcode.com/problems/combination-sum-iii/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Find all possible combinations of k numbers that add up to a number n, 
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *
 * Ensure that numbers within the set are sorted in ascending order.
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 *
 **********************************************************************/
 
class Solution {
public:
	// 0ms, backtracking
    vector<vector<int>> combinationSum3(int k, int n) {
        if( k > 9 || (1+k)*k/2.0 > n || (19-k)*k/2.0 < n )
            return {};
        vector<vector<int>> ans;
        vector<int> comb;
        combine(ans, comb, k, n, 1);
        return ans;
    }
    
    void combine (vector<vector<int>>& ans, vector<int> comb, int remain, int target, int num) {
        if (!remain && !target) {
            ans.push_back(comb);
            return;
        }
        for (int i=num; remain && i<=10-remain; ++i) {
            comb.push_back(i);
            combine(ans, comb, remain-1, target-i, i+1);
            comb.pop_back();
        }
    }
};