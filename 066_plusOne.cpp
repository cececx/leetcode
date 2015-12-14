// Sourse : https://leetcode.com/problems/plus-one/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 **********************************************************************/
 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0 && digits[i] == 9)       // skip digit 9
            digits[i--] = 0;
        if (i >= 0) ++digits[i];               // add 1
        else digits.insert(digits.begin(), 1);
        return digits;
    }
};