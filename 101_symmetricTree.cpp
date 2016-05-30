// Sourse : https://leetcode.com/problems/symmetric-tree/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a binary tree, check whether it is a mirror of itself 
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
    bool isSymmetric(TreeNode* root) {
        return !root || isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* L, TreeNode* R) {
        if(!L || !R) return L == R;
        return L->val == R->val && isMirror(L->left, R->right) && isMirror(L->right, R->left);
    }
};