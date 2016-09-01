// Sourse : https://leetcode.com/problems/meeting-rooms/
// Difficulty : Easy

/***********************************************************************
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
 * determine if a person could attend all meetings.
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return false.
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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        for(int i = intervals.size() - 1; i > 0; i--)
            if (intervals[i].start < intervals[i-1].end)
                return false;
        return true;
    }
};