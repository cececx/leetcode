// Sourse : https://leetcode.com/problems/implement-strstr/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 **********************************************************************/
 
class Solution {
public:
    #define STL
    #ifndef STL
    
	// 4ms, O(n)
    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;
        for(int i=0, j; i<=haystack.size()-needle.size(); ++i) {
            for (j=0; j<needle.size(); ++j)
                if(haystack[i+j]!=needle[j]) break;
            if(j==needle.size()) return i;
        }
        return -1;
    }
    
    #else
    
	// 4ms, using STL
    int strStr(string haystack, string needle) {
        return haystack.find(needle, 0);
    }
    
    #endif
};