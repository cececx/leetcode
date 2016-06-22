// Source : https://leetcode.com/problems/search-a-2d-matrix-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 **********************************************************************/

 
// 260ms. 40%. BinarySearch. O(nlogm)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // mlogn
        // skip smaller lists
        int i = 0, m = matrix[0].size(), n = matrix.size();
        while (i < n && matrix[i][m-1] < target) ++i;
        while (i < n && matrix[i][0] <= target) {
            // do binary search for each row
            int l = 0, r = m - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (matrix[i][mid] < target) l = mid + 1;
                else r = mid;
            }
            if (matrix[i++][l] == target) return true;
        }
        return false;
    }
};

//-------------------------------------------------------------

// 168ms. 93%. Linear approach. O(m + n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start from right top, do it like skip list
        int m = matrix[0].size(), n = matrix.size(), i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] > target) --j;
            else if (matrix[i][j] < target) ++i;
            else return true;
        }
        return false;
    }
};
