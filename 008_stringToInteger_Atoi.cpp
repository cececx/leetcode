// Source : https://leetcode.com/problems/string-to-integer-atoi/
// Difficulty: Easy

/***********************************************************************
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint:
 * 1. If no valid conversion could be performed, a zero value is returned. 
 * 2. If the correct value is out of the range of representable values, 
 *    INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 *
 **********************************************************************/

#include <iostream>
using namespace std;
class Solution {
public:
    // 8ms. Time O(n)
    int myAtoi(string str) {
        long num = 0;
        bool neg = false;
        int i = str.find_first_not_of(' ');
        if (str[i] == '+' || str[i] == '-')
            neg = str[i++] == '-';
        while (isdigit(str[i]) && num <= INT_MAX )
            num = num * 10 + str[i++] - '0';
        return num > INT_MAX ? (neg ? INT_MIN : INT_MAX) : (neg ? -num : num);
    }
};