// Sourse : https://leetcode.com/problems/power-of-two/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 **********************************************************************/
 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};

// if n is a power of 2
// n   = 10000..00
// n-1 =  1111..11 