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
 * Hint:
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 * Did you notice that the reversed integer might overflow? 
 * Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
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