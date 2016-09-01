// Sourse :https://leetcode.com/problems/moving-average-from-data-stream/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 * 
 * For example,
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 *
 **********************************************************************/
 
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : sz(size) {}
    
    double next(int val) {
        if (q.size() == sz) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum / (double) q.size();
    }
private:
    int sz, sum = 0;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */