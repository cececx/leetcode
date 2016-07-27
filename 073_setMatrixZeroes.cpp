// Sourse : https://leetcode.com/problems/set-matrix-zeroes/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *
 **********************************************************************/
 
// 1. Space O(mn) solution: Copy the entire matrix and iterate
// 2. Space O(m+n) solution: Use two bool arrays _column and _raw to store if this column/raw should be set to zero
// 3. Space O(1) solution: Find the first zero, use that raw and column to store the results :D
// Follow up: we only need to store the columns.

// 64ms, beats 97.49% ╭(′▽`)╯ //Time O(mn), Space O(1).
class Solution {
public:
    int find_first_raw_of_zero(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (!matrix[i][j])
                    return i;
        return -1;
    }
    
    void setZeroes(vector<vector<int>>& mat) {
        if (mat.empty()) return;
        int a = find_first_raw_of_zero(mat);
        if (a < 0) return;
        
        int i = 0, j = 0, n = mat.size(), m = mat[0].size();
        // for each raw
        for (int i=a+1; i<n; i++) { 
            bool zero = false;
            for (int j=0; j<m; j++) { // mark columns
                if (!mat[i][j]) { mat[a][j] = 0; zero = true; }
            }
            if (zero) fill(mat[i].begin(), mat[i].end(), 0); // fill current raw
        }
        // fill columns 
        for (int j=0; j<m; j++) 
            if (!mat[a][j])
                for (int i=0; i<n; ++i)
                    mat[i][j] = 0;
        fill(mat[a].begin(), mat[a].end(), 0);
    }
};
