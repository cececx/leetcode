// Sourse : https://leetcode.com/problems/compare-version-numbers/
// Difficulty : Easy

/***********************************************************************
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * 
 **********************************************************************/
 
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.size() || j < version2.size()) {
            int a = 0, b = 0;
            for (; i < version1.size(); ++i) {
                if (version1[i] == '.') break;
                a = a * 10 + version1[i] - '0';
            }
            for (; j < version2.size(); ++j) {
                if (version2[j] == '.') break;
                b = b * 10 + version2[j] - '0';
            }
            if (a > b) return 1;
            if (a < b) return -1;
            ++i, ++j;
        }
        return 0;
    }
};