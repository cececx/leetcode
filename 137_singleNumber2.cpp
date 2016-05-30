// Sourse : https://leetcode.com/problems/single-number-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an array of integers, 
 * every element appears three times except for one.
 * Find that single one.
 *
 * Require Time O(n), Space O(1)
 * 
 **********************************************************************/
 
class Solution {
public:
    // General solution
    int singleNumber (vector<int>& nums) {
        int k = 3;
        int bitsum[32] = {0};
        for (int n : nums) {
            for (int i=0; i<32; ++i) {
                bitsum[i] += n & 1;
                n >>= 1;
            }
        }
        int ret(0);
        for (int i=31; i>=0; --i) {
            ret <<= 1;
            ret |= bitsum[i]%k;
        }
        return ret;
    }
};