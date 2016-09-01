// Sourse : https://leetcode.com/problems/insert-interval/
// Difficulty : Hard

/***********************************************************************
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their start times.
 *
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 **********************************************************************/

 
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval a) {
        vector<Interval> res;
        bool hasInsert = 0;
        for(auto x : intervals) {
            if (hasInsert) res.push_back(x);
            else {
                if (x.start > a.end) { // 合并结束啦
                    hasInsert = 1;
                    res.push_back(a);
                    res.push_back(x);
                }
                else if (x.end >= a.start) { // 我们来开始合并啦！！
                    a.start = min(a.start, x.start);
                    a.end = max(a.end, x.end);
                }
                else res.push_back(x);
            }
        }
        if (!hasInsert) res.push_back(a);
        return res;
    }
};