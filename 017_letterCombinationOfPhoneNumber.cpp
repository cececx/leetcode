// Sourse : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Cecilia Chen
// Date   : 2015-11-06

/***********************************************************************
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 *        2:abc  3:def
 * 4:ghi  5:jkl  6:mno
 * 7:pqrs 8:tuv  9:wxyz
 *
 **********************************************************************/
 
class Solution {
public:

    void dfs(string &ds, int cur, string str, vector<string> &ans) {
        if(cur == ds.size()){ 
            ans.push_back(str);
            return;
        }
        int d = ds[cur] - '2';
        for (int i=0; i< (d==5||d==7?4:3); ++i) {
            str[cur] = d*3 + (d>5?1:0) + i + 'a';
            dfs(ds, cur+1, str, ans);
        }
    }
	
	vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        string str(digits.size(), 0);
        dfs(digits, 0, str, ans);
        return ans;
    }
};