// https://leetcode.com/problems/find-median-from-data-stream/
// Difficulty : Hard

/***********************************************************************
 *
 * Median is the middle value in an ordered integer list. 
 * If the size of the list is even, there is no middle value. 
 * So the median is the mean of the two middle value.
 *
 **********************************************************************/

class MedianFinder {
private:
    priority_queue<int> small; // ensure small.size() >= large.size()
    priority_queue<int, vector<int>, greater<int>> large;
    
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (small.empty()) { small.push(num); return; }
        if (num > small.top()) large.push(num);
        else small.push(num);
        if (small.size() > large.size() + 1) { // small - large > 1，把small挪一个到large
            large.push(small.top());
            small.pop();
        }
        if (large.size() > small.size()) { // large > small
            small.push(large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return small.size() == large.size()
               ? (small.top() + large.top()) / 2.0
               : small.top();
    }
};
