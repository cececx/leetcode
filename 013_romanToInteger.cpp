// Source : https://leetcode.com/problems/roman-to-integer/
// Difficulty: Easy

/***********************************************************************
 *
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 **********************************************************************/
 
// Notes: I(1), V(5), X(10), L(50), C(100), D(500), M(1000)


// Time O(n), Space O(1)
class Solution {
private:
    int getInt(char c) {
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

public:
    int romanToInt(string s) {
        int sum = 0, prev = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            int cur = getInt(s[i]);
            sum += cur < prev ? -cur : cur;
            prev = cur;
        }
        return sum;
    }
};