// Sourse : https://leetcode.com/problems/word-break-ii/
// Difficulty : Hard

/***********************************************************************
 *
 * Given a string s and a dictionary of words dict, 
 * add spaces in s to construct a sentence where each word is a valid dictionary word.
 * Return all such possible sentences.
 * 
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * 
 * A solution is ["cats and dog", "cat sand dog"].
 * 
 **********************************************************************/
 
 
// 首先DP可以在O(n2)时间得到分割方法的总数，不能获得具体分法。
// 然后DFS适合获得解法，然而复杂度过高。
// 所以说我们先DP来标记好从哪里开始可以是有效的，然后在这个基础上DFS就好了。

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        // 来吧天国的DP君
        int n = s.size();
        bool dp[n+1] = {0}; // dp[i] == true 表示从i到结尾是可以哒
        dp[n] = 1; // 最后一位用于标记结尾
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= n; j++) { // 当前词结束位置
                if (dp[j] && wordDict.count(s.substr(i, j - i))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        // 来吧地狱的DFS君
        vector<string> res;
        DFS(s, dp, res, wordDict, "", 0, n);
        return res;
    }
    
    void DFS(string& s, bool* dp, vector<string>& res, unordered_set<string>& set, string cur, int start, int n) {
        if (start == n) {
            res.push_back(cur.substr(0, cur.size() - 1)); // 咔掉结尾空格
            return;
        }
        for (int i = start + 1; i <= n; i++)
            if (dp[i] && set.count(s.substr(start, i - start))) 
                DFS(s, dp, res, set, cur + s.substr(start, i - start) + " ", i, n);
    }
};