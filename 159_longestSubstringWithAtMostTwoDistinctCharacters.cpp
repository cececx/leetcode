// Sourse : https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Difficulty : Hard

/***********************************************************************
 *
 * Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 * 
 * For example, Given s = “eceba”,
 * 
 * T is "ece" which its length is 3.
 *
 **********************************************************************/

 
// 一个Hard题这么简单成何体统
// 将魔幻语言进行到底
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int count[128] = {0};
        int left = 0, right = 0, res = 0, n = s.size(), diff = 0;
        while (right < n) {
            if (!count[s[right++]]++) diff++;
            while (diff > 2) 
                if (!--count[s[left++]]) diff--;
            res = max(res, right - left);
        }
        return res;
    }
};


// 听说代码写成上面这样会被后面的维护者鞭尸
// 所以我决定写一个“说人话”的版本，科科
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int count[128] = {0};
        int left = 0, right = 0, res = 0, n = s.size(), diff = 0;
        while (right < n) {
            if (count[s[right]] == 0) { // <right> reached a new letter
                diff++;
            }
            count[s[right]]++;
            right++;
            while (diff > 2) { // if <diff> is not valid, move <left>
                count[s[left]]--;
                if (count[s[left]] == 0) { // if removed a letter, update <diff>
                    diff--;
                }
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};