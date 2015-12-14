// Sourse : https://leetcode.com/problems/count-and-say/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 **********************************************************************/
 
class Solution {
public:
	// 0ms
    string countAndSay(int n) {
        string ans = "1";
        while(--n) {
            string tmp = "";
            int len = ans.size();
            for(int i=0; i<len; ++i) {
                int start = i;
                while (i+1<len && ans[i]==ans[i+1]) ++i;
                tmp += (char)(i - start + '1') + ans[i];
            }
            ans = tmp;
        }
        return ans;
    }
};