// Sourse : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Cecilia Chen
// Date   : 2015-10-28

/***********************************************************************
 *
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring.
 *
 **********************************************************************/
 
class Solution {
public:
    // O(n), 8ms 
    string longestPalindrome(string s) {
		
         // Initialize s[]->T[]
        string T = s;
        for(int i=s.size(); i>=0; i--)
            T.insert(i, 1, '#');
        T.insert(0, 1, '>');
	    T += '<';
	    int P[2001] = {0};
	    
	    // Manacher
	    int c(0), r(0), index(0), len(0);
	    for(int i = 1; i < T.size() - 1; i++){
	        if(r > i) 
	            P[i] = min(P[2 * c - i], r - i);
	        while(T[i+P[i]+1] == T[i-P[i]-1])
	            ++P[i];
	        if(P[i] + i > r) { 
	            c = i; 
	            r = P[i] + i; 
	        }
	        if(P[i] > len) {
	            len = P[i];
	            index = i;
	        }
	    }
	    return s.substr( (index-len-1)/2, len );
    }
};