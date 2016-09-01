// Sourse : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Difficulty : Hard

/***********************************************************************
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: 
 * left, right, up or down. You may NOT move diagonally or move outside of the boundary 
 * (i.e. wrap-around is not allowed).
 *
 **********************************************************************/
 
// Solution 1: Memorization记忆化搜索
// 用dp[i][j]记录已经完成搜索的格子的最大长度
// Time O(mn), Space O(mn)
class Solution {
private:
    const int delta[5] = {0, 1, 0, -1, 0}; // neighbor[k] = {delta[k], delta[k+1].
    int n, m;
    void DFS(vector<vector<int>>& mat, vector<vector<int>>& len, int i, int j, int& res) {
        if (len[i][j]) return;
        len[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int y = i + delta[k], x = j + delta[k+1];
            if ((y >= 0 && y < n && x >= 0 && x < m) && mat[y][x] > mat[i][j]) {
                DFS(mat, len, y, x, res);
                len[i][j] = max(len[i][j], len[y][x] + 1);
            }
        }
        res = max(len[i][j], res);
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        n = matrix.size(); m = matrix[0].size();      // pre-store size.
        int res = 0;                                  // global variable to store result.
        vector<vector<int>> dp(n, vector<int>(m, 0)); // memorization: store max lenth start at each position
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                DFS(matrix, dp, i, j, res);
        return res;
    }
};



// Solution 2: Topological (Sort + DP)
// 按值排序，获得列表{value, i, j}
// dp[i][j]存储以{i,j}为终点的最大路径长度
// 遍历list同时更新{i,j}上下左右四个位置的dp值

// Time O(mn), Space O(mn). 不晓得为什么这么慢
class Solution {
private:
    struct MatrixNode {
        int val;
        int x;
        int y;
        MatrixNode() : val(0), x(-1), y(-1) {}
        MatrixNode(int val, int y, int x) : val(val), x(x), y(y) {}
    };
    const int delta[5] = {0, 1, 0, -1, 0};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size(), res = 1, k = 0;
        
        // list {value, i, j} sorted by value
        vector<MatrixNode> list(m*n);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                list[k++] = MatrixNode(matrix[i][j], i, j);
        sort(list.begin(), list.end(), [](MatrixNode a, MatrixNode b){ return a.val < b.val; });
        
        // dp[i][j] store the max lenth end at {i, j}
        vector<vector<int>> dp(n, vector<int>(m, 1));
        for (MatrixNode a : list) {
            for (int k = 0; k < 4; k++) {
                int y = a.y + delta[k], x = a.x + delta[k+1];
                if ((y >= 0 && y < n && x >= 0 && x < m) && a.val < matrix[y][x]) {
                    dp[y][x] = max(dp[y][x], dp[a.y][a.x] + 1);
                    res = max(res, dp[y][x]);
                }
            }
        }
        return res;
    }
};