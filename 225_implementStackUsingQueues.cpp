// Sourse : https://leetcode.com/problems/implement-stack-using-queues/
// Difficulty : Easy

/***********************************************************************
 *
 * Implement the following operations of a stack using queues.
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 **********************************************************************/
 
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (q1.empty() && !q2.empty()) {
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q1.empty() && !q2.empty()) {
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
    }

    // Get the top element.
    int top() {
        if (q1.empty() && !q2.empty()) {
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
    
    
private:
    queue<int> q1;
    queue<int> q2;
};