// Sourse : https://leetcode.com/problems/strobogrammatic-number-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 *
 **********************************************************************/

// 用DP存储当前最大及最小结果，每次更新
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int preMax = 1, preMin = 1, res = INT_MIN;
        for (int n : nums) {
            int tmpMax = preMax;
            preMax = max(n, max(n * preMin, n * preMax));
            preMin = min(n, min(n * preMin, n * tmpMax));
            res = max(preMax, res);
        }
        return res;
    }
};