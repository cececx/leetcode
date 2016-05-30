// Sourse : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a binary tree, find its minimum depth.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more than 1.
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
 
 
// Recursive DFS solution
class Solution1 {
public:
    int minDepth (TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};


// ---------------------------------------------------------


// BFS solution: much faster for an unbalanced tree
class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int i = 1;
        while(!Q.empty()) {
            int k = Q.size();
            while (k-- > 0) {
                TreeNode* cur = Q.front();
                Q.pop();
                if(!cur->left && !cur->right) return i;
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            ++i;
        }
    }
};