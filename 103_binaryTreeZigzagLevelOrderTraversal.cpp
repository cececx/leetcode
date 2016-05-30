// Sourse : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *  9  20
 *     /  \
 *    15   7
 * Return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
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
private:
    void DFS (vector<vector<int>>& ans, int depth, TreeNode* node) {
        // reach base
        if (!node) return;
        // reach new level
        if (ans.size() <= depth) ans.push_back(vector<int>());
        // even level
        if (depth & 1) ans[depth].insert(ans[depth].begin(), node->val);
        // odd level
        else ans[depth].push_back(node->val);
        // DFS
        DFS (ans, depth + 1, node->left);
        DFS (ans, depth + 1, node->right);
    }
    
public:    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        DFS(ans, 0, root);
        return ans;
    }
};