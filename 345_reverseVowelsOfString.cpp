// Sourse : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Difficulty : Easy

/***********************************************************************
 *
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 **********************************************************************/

class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            while (!isVowel(s[i])) ++i;
            while (!isVowel(s[j])) --j;
            if (i >= j) break;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};