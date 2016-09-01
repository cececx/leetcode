// Source : https://leetcode.com/problems/missing-ranges/
// Difficulty: Medium

/***********************************************************************
 *
 * Given a sorted integer array where the range of elements are [lower, upper] inclusive, 
 * return its missing ranges.
 * 
 * For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, 
 * return ["2", "4->49", "51->74", "76->99"].
 *
 **********************************************************************/

// 想了想还是重构了一下觉得自己美美哒
class Solution {
public:
    void addRange(vector<string>& res, int start, int end) {
        if (start <= end)
            res.push_back(to_string(start) + (start==end ? "" : "->" + to_string(end)));
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int start = lower, end = lower;
        for (int n : nums) {
            end = n - 1;
            addRange(res, start, end);
            start = n + 1;
        }
        addRange(res, start, upper);
        return res;
    }
};