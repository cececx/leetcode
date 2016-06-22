// Source : https://leetcode.com/problems/palindrome-number/
// Difficulty: Easy

/***********************************************************************
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * Hint: 
 * Negative integers couldn't be palindrome.
 *
 **********************************************************************/

 
// Solution 1: Time O(n), Space O(1)
// 整个翻转. x = 1234 --> y = 4321. return x == y

// Solution 2: Time O(n) * 1/2, Space O(1)
// 翻转一半，考虑奇偶. x = 1234 --> x = 12, y = 43. return x == y || x == y/10
class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 || x > INT_MAX || x && !(x%10) ) return false;  // 排除负数/溢出/末尾是0的数ヽ(●´ω｀●)
        int y = 0;
        while(x > y) {
            y = y * 10 + x % 10;  // 把x的末端添到y的末端
            x /= 10;              // 什么鬼你是端粒酶吗？
        }
        return x == y || x == y/10;  // 相等 或者 刨去中间那位相等
    }
};