// Sourse : https://leetcode.com/submissions/detail/46249893/
// Author : Cecilia Chen
// Date   : 2015-11-17

/***********************************************************************
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by the character '.'.
 * You may assume that there will be only one unique solution.
 *
 **********************************************************************/
 
class Solution {
public:

    // check method: brute force (48ms)   bool matrix (4ms)

    bool col[9][9];
    bool raw[9][9];
    bool grd[3][3][9];
    
    void solveSudoku(vector<vector<char>>& board) {
        memset(col, 0, sizeof(col));   // initialize
        memset(raw, 0, sizeof(raw));
        memset(blk, 0, sizeof(blk));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int a = board[i][j] - '1';
                    raw[i][a] = true;
                    col[j][a] = true;
                    grd[i/3][j/3][a] = true;
                }
            }
        }
        
        solve(board, 0, 0);
    }
    
    // backtracking
    bool solve(vector<vector<char>>& board, int i, in j) {
        if (i >= 9) return true;
        if (board[i][j] != '.') return solve(board, i+(j+1)/9, (j+1)%9);
        
        for (int a = 0; a < 9; ++a) {
            if (!raw[i][a] && !col[j][a] && !grd[i/3][j/3][a]) {
                board[i][j] = a + '1';
                raw[i][a] = true, col[j][a] = true, grd[i/3][j/3][a] = true;
                if (solve(board, i+(j+1)/9, (j+1)%9))
                    return true;
                    
                board[i][j] = '.';
                raw[i][a] = false, col[j][a] = false, grd[i/3][j/3][a] = false;
            }
        }
        return false;
    }
};
