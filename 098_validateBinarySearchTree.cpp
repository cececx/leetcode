// Sourse : https://leetcode.com/problems/validate-binary-search-tree/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 **********************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Notes: input node values can be IN_MIN or INT_MAX.

// Naive Solution:
// * Recursive inorder traversal
// * Store the result in an array. Iterate to check the result.

// Solution 1: Iterative inorder traversal without storing the result
bool isValidBST(TreeNode* root) {
    long pre = (long) INT_MIN - 1;
    TreeNode* cur = root;
    stack<TreeNode*> stk;
    while(cur || !stk.empty()) {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        if (cur->val <= pre) return false;
        pre = cur->val;
        stk.pop();
        cur = cur->right;
    }
    return true;
}

// Solution 2: Recursive with max-min range
class Solution {
public:
    bool isValidBST(TreeNode* root, long minValue = (long)INT_MIN - 1, long maxValue = (long)INT_MAX + 1) {
        if (!root) return true;
        if (root->val >= maxValue || root->val <= minValue) return false;
        bool left = isValidBST(root->left, minValue, root->val);
        bool right = isValidBST(root->right, root->val, maxValue);
        return left && right;
    }
};