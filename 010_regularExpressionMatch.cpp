// Sourse : https://leetcode.com/problems/regular-expression-matching/
// Author : Cecilia Chen
// Date   : 2015-11-12

/***********************************************************************
 *
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 *
 **********************************************************************/
 
class Solution {
public:
    bool isMatch(string s, string p) {
        // isMatchBF (s, p, 0, 0);
        return isMatchDP (s, p);
    }
    
    // 4ms, DP
    // dp[i][j] indicates if s[0...i) matches p[0...j]
    bool isMatchDP(string &s, string &p) {
        const int m = s.size(), n = p.size();
        bool dp[m+1][n+1];
        fill_n(*dp, (m+1)*(n+1), false);
        dp[0][0] = true;
        for (int j=2; j<=n; j+=2) {
            if(dp[0][j-2] && p[j-1]=='*') dp[0][j] = true;
            else break;
        }
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if(p[j-1]=='*')  dp[i][j] = dp[i][j-2] || dp[i-1][j] && ( s[i-1]==p[j-2] || p[j-2]=='.' );
                else dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
            }
        }
        return dp[m][n];
    }
    
    // 100ms, recursive BF
    bool isMatchBF(string &s, string &p, int i, int j) {
        if (j == p.size()) return i == s.size();
        if (i == s.size()) return p[j+1]=='*' && isMatchBF(s, p, i, j+2);
        if (p[j+1] == '*') return isMatchBF(s, p, i, j+2) || (s[i]==p[j] || p[j]=='.') && isMatchBF(s, p, i+1, j);
        return (s[i]==p[j] || p[j]=='.') && isMatchBF(s, p, i+1, j+1);
    }
};
