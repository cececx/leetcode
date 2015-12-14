// Sourse : https://leetcode.com/problems/search-a-2d-matrix/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 *
 **********************************************************************/
 
class Solution {
public:
	// 12ms, binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        int L = 0, R = M*N - 1;
        while(L < R) {
            int mid = (L+R) >> 1;
            int midValue = matrix[mid/N][mid%N];
            if(midValue < target) L = mid + 1;
            else R = mid;
        }
        return matrix[L/N][L%N] == target;
    }
};