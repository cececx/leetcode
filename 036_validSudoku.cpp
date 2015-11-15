// Sourse : https://leetcode.com/problems/valid-sudoku/
// Author : Cecilia Chen
// Date   : 2015-11-15

/***********************************************************************
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 **********************************************************************/
 
class Solution {
public:
    // 12ms
    bool isValidSudoku(vector<vector<char>>& board) {
        short raw[9] = {0}, col[9] = {0}, block[9] = {0};
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j] != '.') {
                    short bit = 1 << (board[i][j] - '1');
                    if(raw[i] & bit || col[j] & bit || block[i/3*3+j/3] & bit)
                        return false;
                    raw[i] |= bit;
                    col[j] |= bit;
                    block[i/3*3+j/3] |= bit;
                }
            }
        }
        return true;
    }
};
