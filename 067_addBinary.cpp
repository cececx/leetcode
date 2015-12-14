// Sourse : https://leetcode.com/problems/plus-one/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 **********************************************************************/
 
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1;
        bool carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int num = (i>=0 ? a[i--]=='1' : 0) + (j>=0 ? b[j--]=='1' : 0) + carry;
            carry = num > 1;
            ans = (char)(num % 2 + '0') + ans;
        }
        return ans;
    }
};
 
 