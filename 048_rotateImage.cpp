// Sourse : https://leetcode.com/problems/rotate-image/
// Difficulty : Medium

/***********************************************************************
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 *
 **********************************************************************/

class Solution {
public:
    // Time O(n), Space O(1)
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());  // vertical
        for (int i = 0; i < matrix.size(); ++i)     // diagonal
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};