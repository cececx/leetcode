// Sourse : https://leetcode.com/problems/integer-to-roman/
// Author : Cecilia Chen
// Date   : 2015-10-28

/***********************************************************************
 *
 * Given an integer, convert it to a roman numeral. 
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 **********************************************************************/
 
class Solution {
public:
	// 28ms. Fast stupic solution
	string intToRoman(int num) {
		string rom;
		while (num > 999) { num -= 1000; rom += 'M';  }
		if    (num > 899) { num -= 900;  rom += "CM"; }
		if    (num > 499) { num -= 500;  rom += 'D';  }
		if    (num > 399) { num -= 400;  rom += "CD"; }
		while (num > 99)  { num -= 100;  rom += 'C';  }
		if    (num > 89)  { num -= 90;   rom += "XC"; }
		if    (num > 49)  { num -= 50;   rom += 'L';  }
		if    (num > 39)  { num -= 40;   rom += "XL"; }
		while (num == 9)  { num -= 10;   rom += 'X';     return rom; }
		if    (num > 8)   { num -= 9;    rom += "IX"; }
		if    (num > 4)   { num -= 5;    rom += 'V';  }
		if    (num == 4)  { num -= 4;    rom += "IV";    return rom; }
		while (num)       { --num;       rom += 'I';  }
		return rom;
    }
	
	// 40ms. Two lines solution for fun :D
	string intToRoman(int num) {
		string p[34] = {"", "M", "MM", "MMM",
						"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
						"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
						"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		return p[num/1000] + p[num%1000/100+4] + p[num%100/10+14] + p[num%10+24];
	}
};