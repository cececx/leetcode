// Source : https://leetcode.com/problems/add-digits/
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

// Math. Time O(1), Space O(1)
// 如果你非要说mod是O(n2)我也没有办法然而事实上硬件运算是O(1)嘻嘻
class Solution {
public:
    int addDigits(int num) {
       return (num-1)%9+1;
    }
};


// Iteration. Time O(???), Space O(1)
class Solution {
public:
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
};