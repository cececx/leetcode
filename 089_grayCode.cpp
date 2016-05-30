// Sourse : https://leetcode.com/problems/gray-code/
// Difficulty : Medium

/***********************************************************************
 *
 * The gray code is a binary numeral system
 * where two successive values differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the code, 
 * print the sequence of gray code.
 *
 * A gray code sequence must begin with 0.
 *
 **********************************************************************/

// Constructing solution: reverse first half, add 1 before the head                         
// 1:      0   1  (1   0)
// 2:     00  01  11  10 (10  11  01  00)
// 3:    000 001 011 010 110 111 101 100
class Solution1 {
public:
    vector<int> grayCode(int n) {
        if (!n) return vector<int>(1, 0);
        vector<int> res = {0, 1};
        for (int i = 1; i < n; ++i) {
            int len = res.size();
            for (int j = len-1; j >= 0; --j) 
                res.push_back(1 << i | res[j]);
        }
        return res;
    }
};
 
// Converting solution: gray = n^n>>1
class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i=0; i<1<<n; ++i) res.push_back(i^i>>1);
        return res;
    }
};