// Sourse : https://leetcode.com/problems/container-with-most-water/
// Author : Cecilia Chen
// Date   : 2015-10-28

/***********************************************************************
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 *
 **********************************************************************/
 
class Solution {
public:
    // 24ms, O(n)
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int area = 0;
        while(l < r) {
            int a = min(height[l], height[r]) * (r - l);
            area = max(a, area);
            height[l] < height[r] ? ++l : --r;
        }
        return area;
    }
    
    /* Notes:
     * 1. If area(x, y) is the max area, then h(i) < h(x), h(j) < h(y) for all i<x, j>y
     * 2. ?: operater is 4ms faster than if else statement
     */
};