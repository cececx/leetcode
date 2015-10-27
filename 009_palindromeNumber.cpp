// Sourse : https://leetcode.com/problems/palindrome-number/
// Author : Cecilia Chen
// Date   : 2015-10-26

/***********************************************************************
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * Hint: 
 * Negative integers couldn't be palindrome.
 *
 **********************************************************************/
 
class Solution {
public:

	// O(logn)
    bool isPalindrome(int x) {
        if(x < 0 || x > INT_MAX || (x!=0 && x%10 == 0)) return false;
        int rev = 0;
        while(x > rev){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev/10;
    }
	
	// O(n) normal solution
	bool isPalindrome1(int x) {
        if(x < 0 || x > INT_MAX)  return false;
        int rev = 0, temp = x;
        while(temp){
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return rev == x;
    }
};