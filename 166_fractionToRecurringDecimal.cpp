// Sourse : https://leetcode.com/problems/fraction-to-recurring-decimal/
// Difficulty : Medium

/***********************************************************************
 *
 * Given two integers representing the numerator and denominator of a fraction, 
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * 
 * For example,
 * 
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 *
 **********************************************************************/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 我们来处理一下前缀和边界条件
        if (!numerator) return "0";
        string res = "";
        if (numerator < 0 ^ 0 > denominator) res += '-';
        long long n = llabs(numerator), d = llabs(denominator);
        // 这里是小数点前的整数部分
        res += to_string(n/d);
        n %= d;
        // 这里是小数点后的小数部分
        if (n) res += ".";
        unordered_map<int, int> map; // 记录余数是n的结果在小数点后第几位
        int i = res.size() - 1; // 初始i标记为小数点位置
        while (n) {
            if (map.count(n)) {
                res.insert(res.begin() + map[n], '(');
                res += ')';
                break;
            }
            map[n] = ++i;
            n *= 10;
            res += to_string(n/d);
            n %= d;
        }
        return res;
    }
};