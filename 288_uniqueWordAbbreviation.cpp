// Sourse : https://leetcode.com/problems/unique-word-abbreviation/
// Difficulty : Hard

/***********************************************************************
 *
 * An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
 * 
 * a) it                      --> it    (no abbreviation)
 * 
 * b) d|o|g                   --> d1g
 *  
 * c) i|nternationalizatio|n  --> i18n
 * 
 * d) l|ocalizatio|n          --> l10n
 * 
 * Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
 * 
 **********************************************************************/

 
 
// 哼哼，预处理的时候肯定要按照长度来分组
// 什么啊，直接初始化记数就好了吧

// NOTE1: 输入的dict中可能有重复的string，需要先转set
// NOTE2: 输入的word可能不在dict中，不在dict时，只要map中有，就是false
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        set = unordered_set<string>(dictionary.begin(), dictionary.end());
        for (string s : set)
            map[abbrev(s)]++;
    }

    bool isUnique(string word) {
        return map[abbrev(word)] == set.count(word);
    }
private:
    string abbrev(string s) {
        int n = s.size();
        return n <= 2 ? s : s[0] + to_string(n-2) + s[n-1];
    }
    unordered_map<string, int> map;
    unordered_set<string> set;
};

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");