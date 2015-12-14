// Sourse : https://leetcode.com/problems/reverse-bits/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 **********************************************************************/
 
 class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for (int i=0; i<32; ++i) {
            ans = (ans<<1) + (n&1);
            n >>= 1;
        }
        return ans;
    }
};