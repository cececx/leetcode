// Sourse : https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty : Hard

/***********************************************************************
 *
 * Given an unsorted array of integers, 
 * find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * 
 * Your algorithm should run in O(n) complexity.
 *
 **********************************************************************/
 
class Solution {
public:
    // set + extend. Time O(n), Space O(n)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int res = 0;
        while(!set.empty()) {
            auto it = set.begin();
            int count = 1;
            for(int x = *it - 1; set.count(x); x--) { count++; set.erase(x); }
            for(int x = *it + 1; set.count(x); x++) { count++; set.erase(x); }
            res = max(res, count);
            set.erase(it);
        }
        return res;
    }
};