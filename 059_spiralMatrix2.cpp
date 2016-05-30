// Sourse : https://leetcode.com/problems/different-ways-to-add-parentheses/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an integer n, generate a square matrix 
 * filled with elements from 1 to n2 in spiral order.
 *
 * input: 3
 * output:
 * [[ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]]
 * 
 **********************************************************************/
 
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int p(0), i(0), num(1), size(n*n);                            // p for padding lol
        while (num <= size) {
            while (i < n-p) res[p][i++] = num++;      i = p + 1;       // →
            while (i < n-p) res[i++][n-p-1] = num++;  i = n - p - 2;   // ↓
            while (i >= p)  res[n-p-1][i--] = num++;  i = n - p - 2;   // ←
            while (i > p)   res[i--][p] = num++;      i = ++p;         // ↑
        }
        return res;
    }
};