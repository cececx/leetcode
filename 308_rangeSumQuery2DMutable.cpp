// Source : https://leetcode.com/problems/range-sum-query-2d-mutable/
// Difficulty: Hard

/***********************************************************************
 *
 * Given a 2D matrix matrix, 
 * find the sum of the elements inside the rectangle defined
 * by its upper left corner (row1, col1) and lower right corner (row2, col2).
 *
 **********************************************************************/

// 这还不好办嘛，记录sum[i][j]表示从左上角加到(i,j)
// Update O(n2): 更新从(r, c)到(n, m)
// SumRegion O(1): sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1]

// 好像Update时间有点高啊要不然我们试试记录rowSums?
// Update O(n), SumRegion O(n)
// 嘻嘻来吧少女www

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        n = matrix.size(), m = matrix[0].size();
        rowSums = matrix;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                rowSums[i][j] += rowSums[i][j-1];
    }

    void update(int row, int col, int val) {
        int delta = val - rowSums[row][col] + (col ? rowSums[row][col-1] : 0);
        for (int j = col; j < m; j++)
            rowSums[row][val] += delta;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++)
            sum += rowSums[i][col2] - (col1 ? rowSums[i][col1-1] : 0);
        return sum;
    }
private:
    vector<vector<int>> rowSums;
    int n = 0, m = 0;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);