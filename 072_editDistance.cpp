// Source : https://leetcode.com/problems/edit-distance/
// Difficulty : Hard

/***********************************************************************
 *
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 * 
 **********************************************************************/

// 成就：hard一遍AC 最优 码好看www 06/15/2016

/*
    dp[i][j]: the edit distance bewteen string s[0]~s[i-1] and string t[0]~t[j-1]

    dp[i][j] = d[i-1][j] + 1 // insert
               d[i][j-1] + 1 // delete
               d[i-1][j-1] + s[i-1] != t[j-1] // replace

    space optimization: p[j] = dp[i][j], r = dp[i-1][j-1]  */

               
// Time O(mn), Space O(m)
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size(), r;
        if (m > n) return minDistance(t, s);
        int p[m+1];
        for (int i=0; i<=m; ++i) p[i] = i;
        for (int i=1; i<=n; ++i) {
            r = p[0]; p[0] = i;
            for (int j=1; j<=m; ++j) {
                r = min( min(p[j], p[j-1]) + 1, r + (s[i-1] != t[j-1]) );
                swap(r, p[j]);
            }
        }
        return p[m];
    }
};
