// Sourse : https://leetcode.com/problems/house-robber-iii/
// Difficulty : Medium

/***********************************************************************
 *
 * The thief has found himself a new place for his thievery again. 
 * There is only one entrance to this area, called the "root." 
 * Besides the root, each house has one and only one parent house. 
 * After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
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
    int dfs (TreeNode* node, int& left, int& right) {
        if (!node) return 0;
        int ll(0), lr(0), rl(0), rr(0);
        left = dfs (node->left, ll, lr);
        right = dfs (node->right, rl, rr);
        return max(node->val + ll + lr + rl + rr, left + right);
    }
public:
    int rob (TreeNode* root) {
        int left(0), right(0);
        return dfs (root, left, right);
    }
};