class Solution {
public:
	// O(n), 12ms
	// storing s.size() and (int)s[i] ahead, optimized runtime from 18ms to 12ms
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