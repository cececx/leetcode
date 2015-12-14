// Sourse : https://leetcode.com/problems/number-of-1-bits/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has.
 * (also known as the Hamming weight).
 *
 **********************************************************************/
 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for (int i=0; i<32; ++i) {
            sum += n&1;
            n >>= 1;
        }
        return sum;
    }
};