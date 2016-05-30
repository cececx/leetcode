// Sourse : https://leetcode.com/problems/binary-search-tree-iterator/
// Difficulty : Medium

/***********************************************************************
 *
 * Implement an iterator over a binary search tree (BST). 
 * Your iterator will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory.
 *
 **********************************************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
 
class BSTIterator {
private:
    stack<TreeNode*> stk;
    void findLeft(TreeNode* node) {
        TreeNode* p = node;
        while (p) {
            stk.push(p);
            p = p->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        findLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* next = stk.top();
        stk.pop();
        if (next->right)
            findLeft(next->right);
        return next->val;
    }
};