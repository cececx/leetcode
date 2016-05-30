// Sourse : https://leetcode.com/problems/word-pattern/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Examples:
 * pattern "abba", str "dog cat cat dog", return true
 * pattern "abba", str "dog cat cat fish", return false
 * pattern "aaaa", str "dog cat cat dog", return false
 * pattern "abba", str "dog dog dog dog", return false
 *
 **********************************************************************/
 
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mapP;   // pattern map
        unordered_map<string, char> mapS;   // substr map
        
        string s;
        vector<string> strs;
        istringstream in(str);
        while(in >> s) strs.push_back(s);   // 安利一个优雅的分割str
        
        if (strs.size() != pattern.size()) return false;
        
        for (int i=0; i<pattern.size(); ++i) {
            if (mapP.find(pattern[i]) == mapP.end()) mapP[pattern[i]] = strs[i];
            if (mapS.find(strs[i]) == mapS.end()) mapS[strs[i]] = pattern[i];
            if (mapP[pattern[i]] != strs[i] || mapS[strs[i]] != pattern[i]) return false;
        }
        return true;
    }
};