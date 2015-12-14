// Sourse : https://leetcode.com/problems/invert-binary-tree/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Invert a binary tree.
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};