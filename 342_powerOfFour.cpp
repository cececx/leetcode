// Sourse : https://leetcode.com/problems/power-of-four/
// Difficulty : Easy

/***********************************************************************
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 *
 **********************************************************************/

class Solution {
public:
    bool isPowerOfFour(int num) {
        return !(num&(num-1)) && (num&0x55555555);
    }
};