// Source : https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Difficulty: Hard

/***********************************************************************
 *
 * Given a string, find the length of the longest substring T that contains at most k distinct characters.
 * For example, Given s = “eceba” and k = 2,
 * T is "ece" which its length is 3.
 *
 **********************************************************************/

// 什么啊，用HashTable存LastIndex吗
// 狗粑粑你同意我写n2吗(..•˘_˘•..) 不行吗，要O(n)啊
// SlidingWindow: maintain a map of K chars. 简直就是用min-heap做k-th largest。保存字母对应的最右坐标。
// 当超过k个字母的时候就把leftmost的字母去掉咯（哼？）
// O(nk)呵呵
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> lastMap;
        int n = s.size(), left = 0, res = 0;
        for (int i = 0; i < n; i++) {
            lastMap[s[i]] = i;
            while (lastMap.size() > k) {
                int leftMost = n;
                char leftChar;
                for (auto& it : lastMap) {
                    if (it.second < leftMost) {
                        leftMost = it.second;
                        leftChar = it.first;
                    }
                }
                lastMap.erase(leftChar);
                left = leftMost + 1;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};

// 我们来存count吧，就是从当前left开始出现过的字母的记数
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[128] = {0}, d = 0, l = 0, res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            d += cnt[s[i]]++ == 0;
            while (d > k)
                d -= --cnt[s[l++]] == 0;
            res = max(res, i - l + 1);
        }
        return res;
    }
};