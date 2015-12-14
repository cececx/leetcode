// Sourse : https://leetcode.com/problems/excel-sheet-column-number/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 *
 **********************************************************************/
 
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (auto ch : s) {
            ans *= 26;
            ans += ch - 'A' + 1;
        }
        return ans;
    }
};