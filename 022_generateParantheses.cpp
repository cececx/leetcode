// Sourse : https://leetcode.com/problems/generate-parentheses/
// Author : Cecilia Chen
// Date   : 2015-11-12

/***********************************************************************
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 **********************************************************************/
 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("", n, 0, ans);
        return ans;
    }
    
    void dfs(string str, int l, int r, vector<string> &ans) {
        if(!l && !r) {
            ans.push_back(str);
            return;
        }
        if(l) dfs (str+'(', l-1, r+1, ans);
        if(r) dfs (str+')', l, r-1, ans);
    }
};
