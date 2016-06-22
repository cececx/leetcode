// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * Example: the root-to-leaf path 1->2->3 represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
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
private:
    int DFS(TreeNode* node, int cur) {
        if (!node) return 0;
        if (!node->left && !node->right) return 10 * cur + node->val;
        else return DFS(node->left, 10*cur + node->val) + DFS(node->right, 10*cur + node->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
};
