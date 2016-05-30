// Sourse : https://leetcode.com/problems/binary-tree-paths/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a binary tree, return all root-to-leaf paths.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return vector<string>();
        vector<string> ans;
        dfs(ans, "", root);
        return ans;
    }
    
    void dfs(vector<string>& ans, string str, TreeNode* node) {
        str += to_string(node->val);
        if (!node->left && !node->right) {
            ans.push_back(str);
            return;
        }
        str += "->";
        if (node->left) dfs(ans, str, node->left);
        if (node->right) dfs(ans, str, node->right);
    }
};