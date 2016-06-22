// Source : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
 * Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
 * You may assume that the input format is always valid
 *
 * "9,3,4,#,#,1,#,#,2,#,6,#,#": true
 * "1,#": false
 * "9,#,#,1": false
 
 **********************************************************************/
 
 
// 8ms. Time O(n), Space O(n)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return true;
        if (preorder[0] == '#') return preorder.size() == 1;
        stack<int> stk;    // stores #child of each node
        stk.push(0);       // push the first node into stack
        for(int i=1; i<preorder.size(); ++i) {
            if (preorder[i] != ',') continue;                 // get the next token
            if (stk.empty()) return false;                    // if the tree is already completed. any further token makes it invalid
            ++ stk.top();                                     // #child + 1
            if (preorder[i+1] != '#') stk.push(0);            // if not a null node, push it into stack
            while(!stk.empty() && stk.top()==2) stk.pop();    // pop the completed nodes
        }
        return stk.empty();
    }
};


/* Analyzing the above solution: 
    * each node is either 0, 1, 2.
    * every time we add a none-empty node, means the tree needs 2 more nodes (remain + 2).
    * every time we add a node, remain - 1.
    * if remain is 0, the tree is completed.
   
   Optimization: replace the stack by a single int */

   

// 4ms. Time O(n), Space O(1)   
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return true;
        if (preorder[0] == '#') return preorder.size() == 1;
        int remain = 2;
        for(int i=1; i<preorder.size(); ++i) {
            if (preorder[i] != ',') continue;        // get the next token
            if (!remain) return false;               // if the tree is already completed. any further token makes it invalid
            -- remain;                               // add this node
            if (preorder[i+1] != '#') remain += 2;   // if not a null node, 2 more nodes are required
        }
        return !remain;
    }
};
