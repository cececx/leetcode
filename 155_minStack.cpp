// Sourse : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Difficulty : Easy

/***********************************************************************
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 **********************************************************************/
 
class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if (min.empty() || x <= getMin())
            min.push(x);
    }

    void pop() {
        int tmp = stk.top();
        stk.pop();
        if (tmp == getMin())
            min.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min.top();
    }
    
private:
    stack<int> stk;
    stack<int> min;
};