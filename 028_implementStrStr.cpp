// Sourse : https://leetcode.com/problems/implement-strstr/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 **********************************************************************/

 
// KMP极简版
class Solution {
public:
    vector<int> getNext(string p) {
        int n = p.size(), i = 1, j = 0;
        vector<int> next(n, 0);
        while (i < n) {
            if (p[i] == p[j]) next[i++] = ++j;
            else if (j > 0) j = next[j-1];
            else next[i++] = 0;
        }
        return next;
    }
    int strStr(string s, string p) {
        if (s.empty() || p.empty()) return p.empty() ? 0 : -1;
        vector<int> next = getNext(p);
        int i = 0, j = 0, n = s.size(), m = p.size();
        while (i < n && j < m) {
            if (s[i] == p[j]) { i++; j++; }
            else if (j > 0) j = next[j-1];
            else i++;
        }
        return j >= m ? i - m : -1;
    }
};


// KMP说人话版
class Solution {
public:
    vector<int> getNext(string p) {
        int n = p.size(), i = 1, j = 0;
        vector<int> next(n, 0);
        while (i < n) {
            if (p[i] == p[j]) {
                next[i] = j + 1;
                i++;
                j++;
            }
            else if (j > 0) {
                j = next[j-1];
            }
            else {
                next[i] = 0;
                i++;
            }
        }
        return next;
    }
    int strStr(string s, string p) {
        if (s.empty() || p.empty()) return p.empty() ? 0 : -1;
        vector<int> next = getNext(p);
        int i = 0, j = 0, n = s.size(), m = p.size();
        while (i < n && j < m) {
            if (s[i] == p[j]) { // matches
                i++;
                j++;
            }
            else if (j > 0) {
                // suppose that next[j-1] = x. from p[0] to p[j-1], p[0]~p[x-1] matches p[j-x+1, j-1]
                // so go ahead and check p[x]
                j = next[j-1];
            }
            else { // not match
                i++;
            }
        }
        if (j >= m) { // pattern match successful
            return i - m;
        }
        return -1;
    }
};