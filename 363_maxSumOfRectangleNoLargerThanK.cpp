// Sourse : https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/
// Difficulty : Hard

/***********************************************************************
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix
 * such that its sum is no larger than k.
 *
 **********************************************************************/
 
// O(n2 mlogm)
// ensure n < m
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size(), res = INT_MIN;
        // handle if (n > m)
        if (n > m) {
            vector<vector<int>> T(m, vector<int>(n));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    T[j][i] = matrix[i][j];
            return maxSumSubmatrix(T, K);
        }
        // iterate rows
        for (int up = 0; up < n; up++) {
            vector<int> sum(m, 0);
            for (int down = up; down < n; down++) {
                for (int i = 0; i < m; i++) {
                    sum[i] += matrix[down][i];
                }
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0;
                for (int s : sum) {
                    curSum += s;
                    auto it = accuSet.lower_bound(curSum - K);
                    if (it != accuSet.end()) res = max(res, curSum - *it);
                    accuSet.insert(curSum);
                }
            }
        }
        return res;
    }
};