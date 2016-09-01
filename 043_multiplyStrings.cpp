// Sourse : https://leetcode.com/problems/multiply-strings/
// Difficulty : Medium

/***********************************************************************
 *
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 **********************************************************************/

// 我的妈呀，BruteForce，二分法，FFT
// 我只想问FFT大数相乘是什么啊！！！！！！
// 我觉得我们就写一下逐位相乘吧Orz
class Solution {
public:
    string multiply(string n1, string n2) {
        // multiply digits
        int sz1 = n1.size(), sz2 = n2.size(), sz3 = sz1 + sz2;
        vector<int> n3(sz3, 0);
        for (int i = 0; i < sz1; i++)
            for (int j = 0; j < sz2; j++)
                n3[i+j] += (n1[sz1-i-1] - '0') * (n2[sz2-j-1] - '0');
        // handle carries
        string res = "";
        int i = 0, extra = 0;
        while (i < sz3 || extra) {
            int a = (i < sz3 ? n3[i++] : 0) + extra;
            res = (char)(a % 10 + '0') + res;
            extra = a / 10;
        }
        // trim 0
        i = res.find_first_not_of('0');
        return i == -1 ? "0" : res.substr(i);
    }
};