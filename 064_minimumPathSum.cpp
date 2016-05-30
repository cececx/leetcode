// Sourse : https://leetcode.com/problems/minimum-path-sum/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 * 
 **********************************************************************/
 
class Solution {
public:
    // Time O(mn), Space O(m)
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp = grid[0];
        int n = grid.size(), m = dp.size();
        for (int i = 1; i < m; ++i) dp[i] += dp[i-1];
        for (int i = 1; i < n; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < m; ++j)
                dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
        }
        return dp[m-1];
    }
};

// Not very into the "no extra space" solution.
// To do this you need to modify the input data. However it's dangerous.

// But yes, you can reduce space from O(mn) to O(m)