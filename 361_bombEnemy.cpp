// Sourse : https://leetcode.com/problems/bomb-enemy/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), 
 * return the maximum enemies you can kill using one bomb.
 * 
 * The bomb kills all the enemies in the same row and column from the planted point until it hits the wall 
 * since the wall is too strong to be destroyed.
 * 
 * Note that you can only put the bomb at an empty cell.
 *
 **********************************************************************/

// Time O(mn), Space O(mn) 并不想再优化了_(:3TZ)_

// 和multiply except self一样！
// 用一个int存当前行，用一个array<int>存当前各列到本行为止的
// 第一次遍历存储dp[i][j]左侧和上侧的敌人和，第二次遍历加上右下，并结算
// inplace存储的话，把enemy换成-1，wall换成-2，用原grid记数即可，那么Time O(mn), Space O(m)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        int cols[m] = {0};
        int rows = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // 正面遍历
        for (int i = 0; i < n; i++) {
            rows = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'E') { cols[j]++; rows++; } // enemy
                else if (grid[i][j] == 'W') { cols[j] = 0; rows = 0; } // wall
                else { dp[i][j] += cols[j] + rows;}
            }
        }
        // 反面遍历
        fill(cols, cols+m, 0);
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            rows = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 'E') { cols[j]++; rows++; } // enemy
                else if (grid[i][j] == 'W') { cols[j] = 0; rows = 0; } // wall
                else { res = max(res, dp[i][j] + cols[j] + rows); }
            }
        }
        return res;
    }
};