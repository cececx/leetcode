// Sourse : https://leetcode.com/problems/length-of-last-word/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 **********************************************************************/
 
class Solution {
public:
	// 4ms, O(n)
    int lengthOfLastWord(string s) {
        int i = s.size()-1, len = 0;
        while (i >= 0 && s[i] == ' ') --i;      // skip space
        while (i >= 0 && s[i--] != ' ') ++len;  // count length
        return len;
    }
};