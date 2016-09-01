// Sourse : https://leetcode.com/problems/word-break/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * 
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * 
 * Return true because "leetcode" can be segmented as "leet code".
 * 
 **********************************************************************/
 
// 来吧我们来找前面标记过的哼哼
// j是s中字符串的front！i是back！
// 在dp里面应该是前一个，但是dp前面多一个！所以！还是j！你们这群小妖精还想整幺蛾子呵呵
// 所以dp[i]的意思就是：第i个前面的是合法的呵呵

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        bool dp[n+1] = {0}; // 表示0到i可以用wwwww
        dp[0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                if (dp[j] && wordDict.count(s.substr(j, i-j+1))) {
                    dp[i+1] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};