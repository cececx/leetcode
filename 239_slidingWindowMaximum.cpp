// Sourse : https://leetcode.com/problems/sliding-window-maximum/
// Difficulty : Hard

/***********************************************************************
 *
 * Given an array nums, there is a sliding window of size k 
 * which is moving from the very left of the array to the very right. 
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 *
 **********************************************************************/

// Solution 1:

// 什么吗，所以这就是一个max queue的数据结构咯
// 好了这一题过wwwww
// ……过你喵

class MaxQueue {
private:
    queue<int> q;
    deque<int> d;
public:
    void push(int val) {
        if (!q.empty())
            while(!d.empty() && d.back() < val)
                d.pop_back();
        q.push(val);
        d.push_back(val);
    }
    void pop() {
        if(d.front() == q.front())
            d.pop_front();
        q.pop();
    }
    int getMax() {
        return d.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MaxQueue q;
        vector<int> res;
        int end = 0, n = nums.size();
        while (end < k - 1) 
            q.push(nums[end++]);
        while (end < n) {
            q.push(nums[end++]);
            res.push_back(q.getMax());
            q.pop();
        }
        return res;
    }
};

// Solution 2:
// 把上面的类实现合并到主函数里可以快好多
// 但是实际应用的时候觉得写类比较好

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int end = 0, n = nums.size();
        vector<int> res;
        while (end < n) {
            while (!q.empty() && q.back() < nums[end]) q.pop_back();
            q.push_back(nums[end++]);
            if (end < k) continue;
            res.push_back(q.front());
            if (q.front() == nums[end - k]) q.pop_front();
        }
        return res;
    }
};