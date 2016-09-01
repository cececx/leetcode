// Sourse : https://leetcode.com/problems/strobogrammatic-number-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 * 
 * Find all strobogrammatic numbers that are of length = n.
 * 
 * For example,
 * Given n = 2, return ["11","69","88","96"].
 *
 **********************************************************************/

// Notes：'0'不能开头啊少女_(:3TZ)_
class Solution {
public:
    unordered_map<char, char> map = unordered_map<char, char>({{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}});
    unordered_set<char> syset = unordered_set<char>({'0', '1', '8'});
    void DFS(vector<string>& res, string cur, int remains) {
        if (!remains) {
            res.push_back(cur);
            return;
        }
        if (remains & 1)
            for (char c : syset)
                DFS(res, cur + c, remains - 1);
        else
            for (auto p : map)
                if (!(remains == 2 && p.first == '0'))
                    DFS(res, p.first + cur + p.second, remains - 2);
    }
    
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        DFS(res, "", n);
        return res;
    }
};