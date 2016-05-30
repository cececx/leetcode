// Sourse : https://leetcode.com/problems/single-number-iii/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an array of numbers nums, 
 * in which exactly two elements appear only once 
 * and all the other elements appear exactly twice. 
 * Find the two elements that appear only once.
 *
 **********************************************************************/
 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, ab = 0;
        for(int n : nums)
            ab ^= n;                // Get A^B
        int lbit = (ab&(ab-1))^ab;  // Get the lowest bit that A differs from B
        for(int n : nums)
            if (n & lbit)
                a ^= n;             // Get A
        return {a, ab ^ a};
    }
};