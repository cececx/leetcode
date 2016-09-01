// Sourse : https://leetcode.com/problems/integer-break/
// Difficulty : Easy

/***********************************************************************
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 *
 **********************************************************************/

// Time O(n), Space O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        stack<int> stk;
        int n = h.size(), res = 0;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && h[stk.top()] > h[i]) {
                int height = h[stk.top()]; stk.pop();
                int last = stk.empty() ? 0 : stk.top() + 1;
                res = max(res, height * (i - last));
            }
            stk.push(i);
        }
        return res;
    }
};