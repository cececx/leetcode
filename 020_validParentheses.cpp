// Sourse : https://leetcode.com/problems/valid-parentheses/
// Author : Cecilia Chen
// Date   : 2015-11-09

/***********************************************************************
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']'
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order.
 * "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 **********************************************************************/
 
class Solution {
public:
    // 0 ms, O(n)
    // Also works if the string contains characters other than parentheses
    bool isValid(string s) {
        stack<char> stk;
        int size = s.size();
        for(char& c : s) {
            if (c=='(' || c=='[' || c=='{')
                stk.push(c);
            else if (c==')' || c==']' || c=='}') {
                if (stk.empty() || stk.top() != (c > 41 ? c-2 : c-1))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
