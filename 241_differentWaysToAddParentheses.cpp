// Sourse : https://leetcode.com/problems/different-ways-to-add-parentheses/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a string of numbers and operators, 
 * return all possible results from computing all the different possible ways to group numbers and operators. 
 * 
 * The valid operators are +, - and *.
 * 
 **********************************************************************/
 
/class Solution {
private:

    // Time cost: switch < function pointer = if-else << if if
    
    vector<int> DP (string& input, int start, int end, map<string, vector<int>>& cache) {
        string key = to_string(start) + to_string(end);
        if(cache.count(key)) return cache[key];
        vector<int> res;
        int num = 0;
        for (int i = start; i <= end; ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = DP(input, start, i-1, cache);
                vector<int> right = DP(input, i+1, end, cache);
                for (int l : left) {
                    for (int r : right) {
                        switch(input[i]) {
                        case '+': res.push_back(l + r); break;
                        case '-': res.push_back(l - r); break;
                        case '*': res.push_back(l * r); break;
                        }
                    }
                }
            }
            else num = num * 10 + (input[i] - '0');
        }
        if (res.empty()) res.push_back(num);
        return cache[key] = res;
    }

public:
    vector<int> diffWaysToCompute(string input) {
        map<string, vector<int>> cache;
        return DP(input, 0, input.size() - 1, cache);
    }
};