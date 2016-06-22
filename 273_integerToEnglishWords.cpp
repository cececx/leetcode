// Source : https://leetcode.com/problems/integer-to-english-words/
// Difficulty : Hard

/***********************************************************************
 *
 * Convert a non-negative integer to its english words representation. 
 * Given input is guaranteed to be less than 2^31 - 1.
 *
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 *
 **********************************************************************/

// 不懂得讨论区的人是怎么写到150多行

class Solution {
private:
    string ones[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                           "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string steps[4] = {"", " Thousand", " Million", " Billion"};
    
    string hundreds(int num) {
        string res = "";
        int h = num / 100, n = num % 100;
        if (h) res = ones[h] + " Hundred" + (n ? " " : "");
        if (n < 20) res += ones[n];
        else res += tens[n/10] + (n%10 ? " " + ones[n%10] : "");
        return res;
    }
    
public:
    string numberToWords(int num) {
        int n[4] = {num / 1000000000, num / 1000000 % 1000, num / 1000 % 1000, num % 1000};
        string res = "";
        for (int i=0; i<4; ++i) {
            if (!n[i]) continue;
            string m = hundreds(n[i]);
            res += (res == "" ? "" : " ") + m + steps[3-i];
        }
        return res == "" ? "Zero" : res;
    }
};