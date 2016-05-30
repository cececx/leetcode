// Sourse : https://leetcode.com/problems/power-of-three/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Follow up: do it without any loop / recursion
 *
 **********************************************************************/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && !(1162261467%n);
    }
};