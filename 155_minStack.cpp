// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Difficulty : Easy

/***********************************************************************
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 **********************************************************************/

 
 
// 1. Two-stack, 52ms. 
class MinStack {
public:
    void push(int x) {
        stk.push_back(x);
        if (min.empty() || x <= min.back())
            min.push_back(x);
    }
    
    void pop() {
        if (stk.back() == min.back())
            min.pop_back();
        stk.pop_back();
    }
    
    int top() { return stk.back(); }
    
    int getMin() { return min.back(); }
    
private:
    deque<int> stk;
    deque<int> min;
};




// 2. One-stack, 52ms
class MinStack {
public:
    void push(int x) {
        if (stk.empty() || x <= min) {
            stk.push_back(min);
            min = x;
        }
        stk.push_back(x);
    }
    
    void pop() {
        if (stk.back() == min) {
            stk.pop_back();
            min = stk.back();
        }
        stk.pop_back();
    }
    
    int top() { return stk.back(); }
    
    int getMin() { return min; }
    
private:
    deque<int> stk;
    int min = INT_MIN;
};