// Sourse : https://leetcode.com/problems/roman-to-integer/
// Author : Cecilia Chen
// Date   : 2015-10-28

/***********************************************************************
 *
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 **********************************************************************/
 
// Notes: I(1), V(5), X(10), L(50), C(100), D(500), M(1000)

class Solution {
public:

	// 36ms
	int romanToInt(string s) {
		int sum = 0, prev = 0;
		for(int i=s.size()-1; i>=0; i--){
			int cur;
			switch(s[i]){
				case 'I': cur = 1; break;
				case 'V': cur = 5; break;
				case 'X': cur = 10; break;
				case 'L': cur = 50; break;
				case 'C': cur = 100; break;
				case 'D': cur = 500; break;
				case 'M': cur = 1000; break;
				default: cur = 0; break;
			}
			sum += cur < prev ? -cur : cur;
			prev = cur;
		}
		return sum;
	}
};