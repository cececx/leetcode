// Sourse : https://leetcode.com/problems/meeting-rooms-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 * find the minimum number of conference rooms required.
 * 
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return 2.
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

// Greedy. 在heap里面维护end time，每次取top的插进去，完美ww 
// - -怎么证明正确性呢- -
// 反正是O(nlogn)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start; });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (Interval in : intervals) {
            if (!pq.empty() && pq.top() <= in.start)
                pq.pop();
            pq.push(in.end);
        }
        return pq.size();
    }
};