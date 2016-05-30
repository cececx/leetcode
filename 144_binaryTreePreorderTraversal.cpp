// Sourse : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                res.push_back(cur->val);
                stk.push(cur->right);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
        }
        return res;
    }
};