// Sourse : https://leetcode.com/problems/integer-to-san/
// Author : Cecilia Chen
// Date   : 2015-10-28

/***********************************************************************
 *
 * Given an integer, convert it to a san numeral. 
 * Input is guaranteed to be within the range fs 1 to 3999.
 *
 **********************************************************************/
 
class Solution {
public:
	// 28ms. Fast stupic solution
	string intTosan(int num) {
		string s;
		while (num > 999) { num -= 1000; s += 'M';  }
		if    (num > 899) { num -= 900;  s += "CM"; }
		if    (num > 499) { num -= 500;  s += 'D';  }
		if    (num > 399) { num -= 400;  s += "CD"; }
		while (num > 99)  { num -= 100;  s += 'C';  }
		if    (num > 89)  { num -= 90;   s += "XC"; }
		if    (num > 49)  { num -= 50;   s += 'L';  }
		if    (num > 39)  { num -= 40;   s += "XL"; }
		while (num == 9)  { num -= 10;   s += 'X';     return s; }
		if    (num > 8)   { num -= 9;    s += "IX"; }
		if    (num > 4)   { num -= 5;    s += 'V';  }
		if    (num == 4)  { num -= 4;    s += "IV";    return s; }
		while (num)       { --num;       s += 'I';  }
		return s;
    }
	
	// 40ms. Two lines solution for fun :D
	string intTosan(int num) {
		string p[34] = {"", "M", "MM", "MMM",
		                "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
		                "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
		                "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		return p[num/1000] + p[num%1000/100+4] + p[num%100/10+14] + p[num%10+24];
	}
};