// Sourse : https://leetcode.com/problems/add-digits/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * 
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 *
 **********************************************************************/
 
class Solution {
public:
    #define SOLUTION1
    #ifdef SOlUTION1
	
	// math solution
    int addDigits(int num) {
       return (num-1)%9+1;
    }
	
    #else
	
    // iterative solution
	int addDigits(int num) {
        int sum = num;
        while (sum > 9) {
            int temp = sum;
            sum = 0;
            while(temp > 0) {
                sum += temp % 10;
                temp = temp / 10;
            }
        }
        return sum;
    }
	
    #endif
};