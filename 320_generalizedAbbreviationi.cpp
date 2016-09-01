// Sourse : https://leetcode.com/problems/generalized-abbreviation/
// Difficulty : Medium

/***********************************************************************
 *
 * Write a function to generate the generalized abbreviations of a word.
 * 
 * Example:
 * Given word = "word", return the following list (order does not matter):
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 *
 **********************************************************************/
 
// Solution 1: Bit Manipulation

// にゃによ？缩写或不缩写任意字符吗，那不就是用binary来表示，呵呵
// 对于每个binary数字，count连续的1位个数，插入0位字母
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int m = word.size(), n = 1 << m;
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string tmp;
            for (int j = 0; j < m;) {
                int count = 0;
                while (j < m && (i & (1 << j))) {
                    count ++;
                    j++;
                }
                if (count) tmp += to_string(count);
                while (j < m && !(i & (1 << j))) {
                    tmp += word[j];
                    j++;
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};


// Solution 2: Backtracking

// 在每一位选择 缩写或不缩写当前字符
// DFS比bit快那么多，わかっていない…
class Solution {
private:
    void DFS(vector<string>& res, string& word, string tmp, int start, int cur) {
        if (cur >= word.size()) {
            if (start != cur)
                tmp += to_string(cur - start);
            res.push_back(tmp);
            return;
        }
        // 缩写当前字符
        DFS(res, word, tmp, start, cur + 1);
        // 不缩写当前字符
        tmp += (cur == start ? "" : to_string(cur - start)) + word[cur];
        DFS(res, word, tmp, cur + 1, cur + 1);
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        DFS(res, word, "", 0, 0);
        return res;
    }
};