// Sourse : https://leetcode.com/problems/reverse-integer/
// Author : Cecilia Chen
// Date   : 2015-10-24

/***********************************************************************
 *
 * Reverse digits of an integer.
 * 
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * Assume that your function returns 0 when the reversed integer overflows.
 *
 **********************************************************************/

class Solution {
public:
	int reverse(int x) {
		// once upon a time there was a long long integer
		long long y = 0;
		while (x) {
			y = 10 * y + x % 10;
			x /= 10;
		}
		// and it lived happy ever after
		return (y < INT_MIN || y > INT_MAX) ? 0 : y;
	}
};
