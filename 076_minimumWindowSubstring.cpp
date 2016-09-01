// Sourse : https://leetcode.com/problems/minimum-window-substring/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a string S and a string T, 
 * find the minimum window in S which will contain all the characters in T in complexity O(n).
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, 
 * return the empty string "".
 * 
 * If there are multiple such windows, 
 * you are guaranteed that there will always be only one unique minimum window in S.
 *
 **********************************************************************/

// right往右直到找到一个符合要求的window
// left往右直到不符合要求

// 如何判断符合要求呢就是一开始用map存字母的count
// right: 每遇到一个就让它减减，每把一个正数减1，就表示匹配了t中的一个字母，于是count加加
// 如果减的是负数就表示是不在t中的字母，没关系我们还会把它加回来的
// left: 每遇到一个数就把它加加，如果加完大于0了，表示丢掉了t中的一个字母，于是count减减

class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {0};
        for(char c : t) map[c]++;
        int n = s.size(), m = t.size();
        int left = 0, right = 0, start = 0, len = INT_MAX, count = 0;
        while (right < n) {
            if (map[s[right++]]-- > 0) count++;
            while (count == m) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                if (++map[s[left++]] > 0) count--;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};