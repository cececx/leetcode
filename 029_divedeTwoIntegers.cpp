// Sourse : https://leetcode.com/problems/divide-two-integers/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 *
 **********************************************************************/
 
class Solution {
public:
	// 8ms, divede-and-conquer
    int divide(int dividend, int divisor) {
        if (!divisor || dividend==INT_MIN && divisor==-1) return INT_MAX; // handle overflow
        if (!dividend) return 0;
		
        bool pos = (dividend>=0)==(divisor>=0); // initialize
        long long a = labs(dividend);
        long long b = labs(divisor);
        long long ans = 0;
        
		while (a >= b) {
            long long tmpDivisor = b, multiply = 1;
            while (a >= (tmpDivisor<<1)) {
                tmpDivisor <<= 1;
                multiply <<= 1;
            }
            a -= tmpDivisor;
            ans += multiply;
        }
		
        return pos ? (ans>INT_MAX ? INT_MAX : ans) : (-ans<INT_MIN ? INT_MIN : -ans);
    }
};