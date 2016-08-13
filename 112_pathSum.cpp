// Sourse : https://leetcode.com/problems/path-sum/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a binary tree and a sum, 
 * determine if the tree has a root-to-leaf path 
 * such that adding up all the values along the path equals the given sum.
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
    bool DFS (TreeNode* node, int remain) {
        if (!node) return false;
        remain -= node->val;
        if (!node->left && !node->right)    // when reaches a leaf node
            return !remain;
        return DFS(node->left, remain) || DFS(node->right, remain);    // check child nodes
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return root && DFS(root, sum);
    }
};