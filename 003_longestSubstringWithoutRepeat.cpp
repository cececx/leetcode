// Sourse : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Cecilia Chen
// Date   : 2015-10-23

/***********************************************************************
 *
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 * For "bbbbb" the longest substring is "b", with the length of 1.
 *
 **********************************************************************/

class Solution {
public:
	// O(n), 12ms
	// store s.size() and (int)s[i] ahead. runtime: 18ms -> 12ms
	int lengthOfLongestSubstring(string s) {
		int offset(0), len(0);
		int pos[128];
		memset(pos, -1, sizeof(int) * 128);
		int size = s.size();
		for (int i; i < size; i++) {
			int ch = s[i];
			if (pos[ch] != -1) {
				len = max(len, i - offset);
				offset = max(pos[ch] + 1, offset);
			}
			pos[ch] = i;
		}
		len = max(len, size - offset);
		return len;
	}
};
