// Sourse : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author : Cecilia Chen

// Difficulty : Hard

/***********************************************************************
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
	// 0ms, stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        
        while (cur != NULL) {
           ans.insert(ans.begin(), cur->val);
           if (cur->left != NULL) stk.push(cur->left);
           if (cur->right != NULL) cur = cur->right;
           else {
               if (stk.empty()) break;
               cur = stk.top();
               stk.pop();
           }
        }
        
        return ans;
    }
};