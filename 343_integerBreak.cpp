// Sourse : https://leetcode.com/problems/integer-break/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a positive integer n, 
 * break it into the sum of at least two positive integers
 * and maximize the product of those integers. 
 * Return the maximum product you can get.
 *
 **********************************************************************/

class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) return n-1;
        int r = n%3;
        switch(r) {
            case 0: return (int) pow(3, n/3); break;
            case 1: return (int) (4 * pow(3, (n-4)/3)); break;
            case 2: return (int) (2 * pow(3, (n-2)/3)); break;
        }
        return 0;
    }
};