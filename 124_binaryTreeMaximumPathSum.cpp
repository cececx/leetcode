// Source : https://leetcode.com/problems/integer-to-english-words/
// Difficulty : Hard

/***********************************************************************
 *
 * Given a binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes 
 * from some starting node to any node in the tree along the parent-child connections. 
 * The path does not need to go through the root.
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
 
// DFS, O(n)
class Solution {
public:
    int maxPath(TreeNode* node, int& sum) {
        if(!node) return 0;
        int left = maxPath(node->left, sum);    // max sum of left nodes
        int right = maxPath(node->right, sum);  // max sum of right nodes
        sum = max(node->val + max(0,left) + max(0, right), sum);  // add child sum if it's possitive
        return node->val + max(0, max(left, right));    // return max sum of this node
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxPath(root, sum);
        return sum;
    }
};
