// Sourse : https://leetcode.com/problems/binary-tree-level-order-traversal/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a binary tree, return the level order traversal of its nodes' values
 *
 * Given binary tree {3,9,20,#,#,15,7},
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *
 * Return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        DFS(ans, 0, root);
        return ans;
    }
    
private:
    void DFS (vector<vector<int>>& ans, int depth, TreeNode* node) {
        if (!node) return;
        if (ans.size() <= depth) ans.push_back(vector<int>());
        ans[depth].push_back(node->val);
        DFS (ans, depth + 1, node->left);
        DFS (ans, depth + 1, node->right);
    }
};