// Sourse : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1 = min(p->val, q->val);
        int v2 = max(p->val, q->val);
        while (v1 > root->val || v2 < root->val) {
            if (v1 > root->val) root = root->right;
            else root = root->left;
        }
        return root;
    }
};