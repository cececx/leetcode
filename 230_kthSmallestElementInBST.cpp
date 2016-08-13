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
 
 /*
 
 写一个inorder的递归，有一个remain，表示剩余要找的还有多少
 因为要找第k个，所以一开始remain = k
 先递归访问所有左节点，也就是所有比当前小的
 左边都访问完了以后，remain的数值是刨去左边所有节点，还需要多少个
 remain - 1，也就是算上了当前节点，如果是0了就返回当前节点
 如果还大于零，就去找node->right
 
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