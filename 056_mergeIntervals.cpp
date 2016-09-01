// Source : https://leetcode.com/problems/merge-intervals/
// Difficulty: Hard

/***********************************************************************
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
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
 
 
// 我，我先sort行不行_(:3TZ)_
// 华丽优雅的本宫再次一遍AC了hard，大赦天下以庆贺wwwwww
// 顺手学会了lambda表达式

// Time O(nlogn), Extra space O(n)
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return (a.start < b.start);});
        vector<Interval> res;
        int start = intervals[0].start, end = intervals[0].end;
        for (Interval cur : intervals) {
            if (cur.start > end) {
                res.push_back(Interval(start, end));
                start = cur.start;
            }
            end = max(cur.end, end);
        }
        res.push_back(Interval(start, end));
        return res;
    }
};