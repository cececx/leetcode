// Sourse : https://leetcode.com/problems/isomorphic-strings/
// Difficulty : Easy

/***********************************************************************
 *
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 **********************************************************************/
 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        char maps[128] = {0}; // maps[i]: the position that letter i appeared for the last time
        char mapt[128] = {0};
        for (int i=0; i<s.size(); ++i) {
            if (maps[s[i]] != mapt[t[i]]) return false;
            maps[s[i]] = i + 1;
            mapt[t[i]] = i + 1;
        }
        return true;
    }