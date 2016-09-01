// Sourse: https://leetcode.com/problems/largest-number/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 **********************************************************************/

// 其实只要加一下试试就好了: (34, 3) { return 343 > 334; }
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ss;
        for (int n : nums)
            ss.push_back(to_string(n));
        sort(ss.begin(), ss.end(), [](string& a, string& b){ return a + b > b + a; });
        string res;
        for (string s : ss)
            res += s;
        // trim zeros
        int a = res.find_first_not_of('0');
        return a == -1 ? "0" : res.substr(a);
    }
};