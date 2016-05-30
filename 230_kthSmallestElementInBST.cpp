// Sourse : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary search tree, 
 * write a function kthSmallest to find the kth smallest element in it.
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
    void inorder (TreeNode* node, int& remain, int& val) {
        if (!node) return;
        inorder (node->left, remain, val);
        if (!(--remain)) {
            val = node->val;
            return;
        }
        inorder (node->right, remain, val);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        inorder (root, k, res);
        return res;
    }
};

// 在漫咖啡写的第一条Leetcode，彼时正在帮旁边的小伙伴优化码ヽ(●´ω｀●)