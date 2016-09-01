// Sourse: https://leetcode.com/problems/powx-n/
// Difficulty : Medium

/***********************************************************************
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * 
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 **********************************************************************/
 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            if (s!="+" && s!="-" && s!="*" && s!="/")
                stk.push(stoi(s));
            else {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                int c;
                switch(s[0]) {
                    case '+': c = b + a; break;
                    case '-': c = b - a; break;
                    case '*': c = b * a; break;
                    case '/': c = b / a; break;
                    default: break;
                }
                stk.push(c);
            }
        }
        return stk.top();
    }
};