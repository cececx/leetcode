// Sourse : https://leetcode.com/problems/longest-common-prefix/
// Author : Cecilia Chen
// Date   : 2015-10-28

/***********************************************************************
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 **********************************************************************/
 
class Solution {
public:
	// 4ms	 
	string longestCommonPrefix(vector<string>& strs) {
		if(strs.empty()) return "";
		for(int idx = 0; idx < strs[0].size(); idx++){
			for(int i = 1; i < strs.size(); i++){
				if(idx >= strs[i].size() || strs[i][idx] != strs[0][idx])
					return strs[0].substr(0, idx);
			}
		}
		return strs[0];
	}
};

// O(mn)? 这么任性我也是醉舞九天wwww