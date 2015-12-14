// Sourse : https://leetcode.com/problems/happy-number/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * Example: 19 is a happy number
 *   1^2 + 9^2 = 82
 *   8^2 + 2^2 = 68
 *   6^2 + 8^2 = 100
 *   1^2 + 0^2 + 0^2 = 1
 *
 **********************************************************************/
 
class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            int sum = 0;
            while (n) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};