// Sourse : https://leetcode.com/problems/valid-anagram/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 **********************************************************************/
 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int ch[255] = {0};
        for (int i=0; i<s.size(); ++i) {
            ++ ch[s[i]];
            -- ch[t[i]];
        }
        for (int i=0; i<255; ++i)
            if (ch[i])
                return false;
        return true;
    }
};