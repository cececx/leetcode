// Sourse : https://leetcode.com/problems/summary-ranges/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 **********************************************************************/
 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int a = 0, n = nums.size();
        if (!n) return vector<string>();
        vector<string> v;
        while (a < n) {
            int b = a;
            while (b + 1 < n && nums[b] + 1 == nums[b + 1]) ++b;
            v.push_back(a == b ? to_string(nums[b]) : to_string(nums[a]) + "->" + to_string(nums[b]));
            a = b + 1;
        }
        return v;
    }
};

// C程序员命名大法ヽ(●´ω｀●)