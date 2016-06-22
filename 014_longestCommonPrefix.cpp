// Source : https://leetcode.com/problems/longest-common-prefix/
// Difficulty: Easy

/***********************************************************************
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 **********************************************************************/
 
// m = length of one string
// k = #strings
 
 

// Time O(mk), Space O(1)
class Solution {
public:
	string longestCommonPrefix(vector<string>& s) {
	    if (strs.empty()) return ""; // empty input
	    
		for (int j = 0; j < s[0].size(); j++)   // each char in 1st line
			for (int i = 1; i < s.size(); i++)  // other lines
				if(j >= s[i].size() || s[i][j] != s[0][j]) // index reached the end / char is diff from str[0]
					return s[0].substr(0, j);

		return strs[0];
	}
};
