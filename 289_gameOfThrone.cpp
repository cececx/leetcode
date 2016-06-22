// Source : https://leetcode.com/problems/game-of-life/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 * Any live cell with two or three live neighbors lives on to the next generation.
 * Any live cell with more than three live neighbors dies, as if by over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 *
 **********************************************************************/

 
// Solution 1: 原状态累加到右下格子

class Solution {
public:
    void update(vector<vector<int>>& board, int i, int j, int n, int m) {
        if (j + 1 < m) {
            board[i][j+1] += (board[i][j]&1) * 2;
            board[i][j] += (board[i][j+1]&1) * 2;
        }
        for (int k = max(j-1, 0); i + 1 < n && k <= min(j+1, m-1); ++k) {
            board[i+1][k] += (board[i][j]&1) * 2;
            board[i][j] += (board[i+1][k]&1) * 2;
        }
        board[i][j] = board[i][j] >= 5 && board[i][j] <= 7;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int m = board[0].size(), n = board.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                update(board, i, j, n, m);
    }
};



// -----------------------------------------------------------------------------



// Solution 2: 新状态存在bit第二位

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int m = board[0].size(), n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int count = 0;
                for (int a = max(0, i-1); a <= min(i+1, n-1); ++a)
                    for (int b = max(0, j-1); b <= min(j+1, m-1); ++b)
                        count += board[a][b] & 1;
                board[i][j] |= (count == 3 || count - board[i][j] == 3) << 1;
            }
        }
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                board[i][j] >>= 1;
    }
};
