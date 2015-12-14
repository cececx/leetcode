// Sourse : https://leetcode.com/problems/climbing-stairs/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 **********************************************************************/
 
class Solution {
public:
	// 0ms, simplified dp
    int climbStairs(int n) {
        int a = 1, b = 1;
        for(int i=1; i<n; ++i) {
            b += a;
            a = b - a;
        }
        return b;
    }
};