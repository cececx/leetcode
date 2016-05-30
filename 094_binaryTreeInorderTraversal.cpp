// Sourse : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
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
 
 
class Solution {
public:

    // Recursive solution都是渣渣wwwww
    
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        vector<int> res;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;        // the deepest left node
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);    // add last node
            cur = cur->right;           // get right. if right=null, next step will pop the last node
        }
        return res;
    }
};