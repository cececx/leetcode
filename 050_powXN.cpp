// Sourse: https://leetcode.com/problems/powx-n/
// Difficulty : Medium

/***********************************************************************
 *
 * Implement pow(x, n).
 *
 **********************************************************************/

// Solution 1: pow(x, n) = pow(x, n/2) * pow(x, n/2) * (n&1 ? x : 1);
// Solution 2: x^9 = x^(2^3) * x^(2^1)

// Time O(logn)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long N = labs((long)n);
        double res = 1;
        for (; N > 0; x *= x, N >>= 1)
            if (N & 1)
                res *= x;
        return n > 0 ? res : 1/res;
    }
};