// Sourse : https://leetcode.com/problems/implement-queue-using-stacks/
// Difficulty : Easy

/***********************************************************************
 *
 * Implement the following operations of a queue using stacks.
 * 
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * 
 **********************************************************************/
 
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stackin.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (stackout.empty()) {
            while (!stackin.empty()) {
                stackout.push(stackin.top());
                stackin.pop();
            }
        }
        if (!stackout.empty()) {
            stackout.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (stackout.empty()) {
            while (!stackin.empty()) {
                stackout.push(stackin.top());
                stackin.pop();
            }
        }
        return stackout.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stackin.empty() && stackout.empty();
    }
    
    
private:
    stack<int> stackin;
    stack<int> stackout;
};