// Sourse : https://leetcode.com/problems/binary-tree-right-side-view/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary tree, imagine yourself standing on the right side of it, 
 * return the values of the nodes you can see ordered from top to bottom.
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
    void DFS (vector<int>& res, TreeNode* node, int depth) {
        if (!node) return;
        if (depth >= res.size()) res.push_back(node->val);
        DFS(res, node->right, depth + 1);
        DFS(res, node->left, depth + 1);
    }
public:
    // Time O(n), Space O(depth)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        DFS(res, root, 0);
        return res;
    }
};