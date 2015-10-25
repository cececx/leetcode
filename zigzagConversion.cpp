// Sourse : https://leetcode.com/problems/zigzag-conversion/
// Author : Cecilia Chen
// Date   : 2015-10-24

/***********************************************************************
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 **********************************************************************/

/* find the pattern:
 * 0           6           12          18
 *   1       5   7       11  13      17  19
 *     2   4       8   10      14  16      20
 *       3           9           15
 */

class Solution {


public:

	string convert(string s, int numRows) {
		return solution2(s, numRows);
	}
	
	// 16ms solution:
	string solution2(string s, int numRows) {		
		if (s.size() <= numRows || numRows <= 1) return s;
		string z;
		int size = s.size(), len = numRows * 2 - 2;
		// first row
		for (int i = 0; i<size; i += len)
			z += s[i];
		// others
		for (int row = 1; row<numRows - 1; row++) {
			int i = row, j = len - i;
			for (; j<size; i += len, j += len) {
				z += s[i];
				z += s[j];
			}
			if (i<size) z += s[i];
		}
		// last row
		for (int i = numRows - 1; i<size; i += len)
			z += s[i];
		return z;
	}

	// 24ms solution
	string solution1(string s, int numRows) {
		
		if (numRows <= 1) return s;
		string result[numRows];
		int size = s.size();
		int row, len = numRows * 2 - 2;

		// calc index
		for (int i = 0; i<size; i++) {
			row = i % len;
			row = row < numRows ? row : len - row;
			result[row] += s[i];
		}
		
		string z;
		for (int i = 0; i<numRows; i++) {
			ret += result[i];
		}
		return z;
	}
};
