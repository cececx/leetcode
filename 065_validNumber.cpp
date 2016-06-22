// Source : https://leetcode.com/problems/valid-number/
// Difficulty : Hard

/***********************************************************************
 *
 * Validate if a given string is numeric.
 *
 **********************************************************************/

 /*
 
 原题说可以从给的例子里面获得所有requirementヽ(●´ω｀●)
 再跟我提例子我neng死你→  →
 
 基本上parse规则就是
 
 valid_answer: <space> <valid_number> <space> 
 valid_number: <real_number> | <real_number> "e" <integer>
 real_number:  ("+"|"-")? <digit>* "." <digit>*  // at least 1 digit
 integer:      ("+"|"-")? <digit>+
 
 */
 
class Solution {
private:
    // <digits>
    bool isDigits(string s) {
        for (char c : s) if (!isdigit(c)) return false;
        return true;
    }

    // remove '+' or '-' in the front
    string removeMark(string s) {
        if (!s.empty() && s[0] == '+' || s[0] == '-') return s.substr(1);
        return s;
    }

    // check <integer>
    bool isInt(string s) {
        s = removeMark(s);
        return !s.empty() && isDigits(s);
    }

    // check <real_number>
    bool isNum(string s) {
        s = removeMark(s);
        int p = s.find_first_of('.');
        if (p == -1) return !s.empty() && isDigits(s);
        else return s.size() > 1 && (isDigits(s.substr(0, p)) && isDigits(s.substr(p+1)));
    }

public:
    bool isNumber(string s) {
        // trim
        int a = s.find_first_not_of(' '), b = s.find_last_not_of(' ');
        if (a == -1) return false;
        s = s.substr(a, b - a + 1);

        // split by 'e'
        int e = s.find_first_of('e');
        if (e == -1) return isNum(s);
        else return (isNum(s.substr(0, e)) && isInt(s.substr(e+1)));
    }
};