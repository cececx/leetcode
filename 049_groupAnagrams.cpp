// Sourse : https://leetcode.com/problems/anagrams/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Given an array of strings, group anagrams together.
 *
 * Input:  ["eat", "tea", "tan", "ate", "nat", "bat"]
 * Output: [ ["ate", "eat","tea"],
 *           ["nat","tan"],
 *           ["bat"] ]
 *
 **********************************************************************/
 
class Solution {
public:
	// 72ms, hash map
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        int i=0;
        for (string s : strs) {
            sort(s.begin(), s.end());
            map[s].push_back(strs[i++]);
        }
        for (pair<string, vector<string>> anagram : map) {
            sort(anagram.second.begin(), anagram.second.end());
            ans.push_back(anagram.second);
        }
        return ans;
    }
};