// Source : https://leetcode.com/problems/triangle/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a triangle, find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 *
 * input:               output: 
 * [
 *      [2],            2 + 3 + 5 + 1 = 11
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 **********************************************************************/

// DP. Time O(n2), Space O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j <= i; ++j)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        return dp[0];
    }
};
