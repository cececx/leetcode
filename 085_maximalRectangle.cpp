// Sourse : https://leetcode.com/problems/integer-break/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 6.
 *
 **********************************************************************/


// dp[i][j]记录[i][j]往上有多少个
// 然后用柱状图来做嘻嘻我是不是应该先把柱状图那道题做了→  →

// Time O(n2) Space O(n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty()) return 0;
        const int n = mat.size(), m = mat[0].size();
        vector<int> dp(m + 1, 0); // optimize space
        int res = 0;
        for (int i = 0; i < n; i++) {
            stack<int> stk;
            for (int j = 0; j < m + 1; j++) {
                dp[j] = mat[i][j] == '1' ? dp[j] + 1 : 0; // update dp matrix
                while(!stk.empty() && dp[stk.top()] > dp[j]) {
                    int index = stk.top();
                    stk.pop();
                    // 除了stk.top()以外其它都是比index高的，所以left应该是stk.top() + 1
                    res = max(res, dp[index] * (j - (stk.empty() ? 0 : stk.top() + 1)));
                }
                stk.push(j);
            }
        }
        return res;
    }
};

// 还有一个纯DP的解，臣妾姑且还没看懂

// left[i][j] = max(left[i-1][j], cur_left), cur_left is the left most 1 in the current row
// right[i][j] = min(right[i-1][j], cur_right), cur_right is the right most 1
// height[i][j] is the height
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty()) return 0;
        const int n = mat.size(), m = mat[0].size(), res = 0;
        int left[m] = {0}, right[m], height[m] = {0};
        fill(right, right + m, m);
        for (int i = 0; i < n; i++) {
            int cur_left = 0, cur_right = m;
            for (int j = 0; j < m; j++) {
                // height
                height[j] = mat[i][j] == '1' ? height[j] + 1 : 0;
                // left
                if (mat[i][j] == '1') left[j] = max(left[j], cur_left);
                else { left[j] = 0; cur_left = j+1; }
            }
            for (int j = m - 1; j >= 0; j--) {
                // right
                if (mat[i][j] == '1') right[j] = min(right[j], cur_right);
                else { right[j] = m; cur_right = j; }
                // calc
                res = max(res, height[j] * (right[j] - left[j]));
            }
        }
        return res;
    }
};