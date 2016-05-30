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
        remain -= node->val;
        if (!node->left && !node->right)    // when it's the leaf node
            return !remain;                 // if remain = 0, sum equals to target sum
        return (node->left ? DFS(node->left, remain) : false)       // check left node
            || (node->right ? DFS(node->right, remain) : false);    // check right node
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return root && DFS(root, sum);
    }
};