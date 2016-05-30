// Sourse : https://leetcode.com/problems/unique-paths/
// Difficulty : Medium

/***********************************************************************
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 **********************************************************************/

// DP Solution: Time O(mn), Space O(m)
class Solution1 {
public:
    
    int uniquePaths(int m, int n) {
        if (m > n) swap(m, n);
        vector<int> dp(m, 1);
        for (int i=1; i<n; ++i)
            for (int j=1; j<m; ++j)
                dp[j] = dp[j-1] + dp[j];
        return dp[m-1];
    }
};



// Math Solution: Time O(m), Space O(1)
// --> P(n+m)/(P(n-1)*P(m-1)) = C(n+m-2)(n-1)
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        if (m > n) swap(m, n);
        for (int i=1; i<m; ++i)
            ans = ans*(n+i-1)/i;
        return ans;
    }
};