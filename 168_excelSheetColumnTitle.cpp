// Sourse : https://leetcode.com/problems/excel-sheet-column-title/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * 26 -> Z
 * 27 -> AA
 *
 **********************************************************************/
 
 class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n) {
            char ch = (n-1) % 26 + 'A';
            ans = ch + ans;
            n = (n-1) / 26;
        }
        return ans;
    }
};