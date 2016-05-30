// Sourse : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * Return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
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
    void DFS(vector<vector<int>>& ans, int depth, TreeNode* node) {
        if (!node) return;
        if (ans.size() <= depth) ans.push_back(vector<int>());
        ans[depth].push_back(node->val);
        DFS(ans, depth + 1, node->left);
        DFS(ans, depth + 1, node->right);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        DFS(ans, 0, root);
        return vector<vector<int>> (ans.rbegin(), ans.rend()); // reverse levels
    }
};