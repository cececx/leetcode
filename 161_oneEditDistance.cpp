// Source : https://leetcode.com/problems/one-edit-distance/
// Difficulty: Medium

/***********************************************************************
 *
 * Given two strings S and T, determine if they are both one edit distance apart.
 *
 **********************************************************************/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // let len(s) > len(t)
        int i=0, j=0, n=s.size(), m=t.size();
        if (n < m) return isOneEditDistance(t, s);
        if (n > m + 1) return false;
        
        // find the first not match
        while (i < n && j < m) {
            if (s[i] != t[j]) break;
            i++; j++;
        }
        
        // if at least one string reaches the end
        if (j == m) return n == m + 1;
        
        // else
        return s.substr(i+1) == t.substr(j) 
            || s.substr(i+1) == t.substr(j+1);
    }
};