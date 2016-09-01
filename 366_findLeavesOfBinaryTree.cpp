// Sourse : https://leetcode.com/problems/find-leaves-of-binary-tree/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary tree, collect a tree's nodes as if you were doing this: 
 * Collect and remove all leaves, repeat until the tree is empty.
 *
 * Example:
 * Given binary tree 
 *         1
 *        / \
 *       2   3
 *      / \     
 *     4   5    
 * Returns [4, 5, 3], [2], [1].
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

// bottom-up，记录当前节点的最大深度
class Solution {
public:
    /** @return depth of current node. leaf is 1. */
    int dfs(TreeNode* node, vector<vector<int>>& res) {
        if (!node) return 0;
        int d = max(dfs(node->left, res), dfs(node->right, res)) + 1;
        while(res.size() < d) res.push_back(vector<int>());
        res[d-1].push_back(node->val);
        return d;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
};