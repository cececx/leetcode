// Sourse : // Sourse : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an input string, reverse the string word by word.
 *
 * Clarification:
 * 1. A sequence of non-space characters consitutes a word
 * 2. Reversed string should not contain leading / trailing / multiple spaces
 *
 **********************************************************************/

 
// 8ms, Time O(n), Space O(n)
class Solution1 {
public:
    void reverseWords(string &s) {
        istringstream ss(s);
        ss >> s;
        string a;
        while (ss >> a) s = a + ' ' + s;
        if (s[0] == ' ') s = "";
    }
}; 


// 8ms, in place one pass, Time O(n), Space O(1)
class Solution2 {
public:
    void reverseWords(string &s) {
        int cur = 0, size = s.size();
        for (int i = 0; i < size; ++i) {
            if (s[i] == ' ') continue;  // skip extra space
            if (cur) s[cur++] = ' ';    // add space before next word
            int end = i;
            while (end < size && s[end] != ' ')
                s[cur++] = s[end++];
            reverse(s.begin() + cur + i - end, s.begin() + cur);
            i = end;
        }
        s.erase(s.begin() + cur, s.end());
        reverse(s.begin(), s.end());
    }
};
