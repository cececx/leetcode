// Sourse : https://leetcode.com/problems/basic-calculator/
// Difficulty : Hard

/***********************************************************************
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 *
 **********************************************************************/
 
class Solution {
public:
    int calculate(string s) {
        // 把符号压栈好了wwwww stk.top()是当前这个括号外面的正负
        stack<bool> stk({1});
        bool opt = true;
        int res = 0, num = 0;
        for (int i = 0; i < s.size(); i++) {
            int num = 0;
            if (s[i] == '+' || s[i] == '-') opt = !(stk.top()^(s[i] == '+'));
            else if (s[i] == '(') stk.push(opt);
            else if (s[i] == ')') stk.pop();
            else if (isdigit(s[i])) {
                while (i < s.size() && isdigit(s[i]))
                    num = 10 * num + s[i++] - '0';
                res += opt ? num : -num;
                num = 0;
                i--;
            }
        }
        return res;
    }
};