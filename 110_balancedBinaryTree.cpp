// Sourse : https://leetcode.com/problems/balanced-binary-tree/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more than 1.
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
    // return depth, or -1 if the node is not balanced
    int depth(TreeNode* node) {
        if(!node) return 0;
        int LD = depth(node->left);
        int RD = depth(node->right);
        return (abs(LD - RD) > 1 || LD==-1 || RD==-1) ? -1 : max(LD, RD) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }    
};