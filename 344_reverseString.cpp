// Sourse : https://leetcode.com/problems/reverse-string/
// Difficulty : Easy

/***********************************************************************
 *
 * Write a function that takes a string as input and returns the string reversed.
 *
 **********************************************************************/

class Solution {
public:
    string reverseString(string s) {
        int len = s.length() / 2;
        for (int i = 0, j = s.length() - 1; i < len; ++i, --j) {
            swap(s[i], s[j])
        return s;
    }
};