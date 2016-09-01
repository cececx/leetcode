// Sourse : https://leetcode.com/problems/inorder-successor-in-bst/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 * Note: If the given node has no in-order successor in the tree, return null.
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

// Naive Solution:
// * 若P有右子树，找到右子树的最左
// * 否则，从root开始搜索，将路径入栈，找到P后，返回栈中最后一个比P大的节点

// Optimized:
// * 既然要找最后一个比P大的节点，在遍历时存一个<suc>变量即可
// * 每当cur > P时，将suc更新为cur，并往左找
// * 否则不更新，并往右找

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    // 嫌弃root名字不好听，我们来新建一个用来iterate的cur（笑
    TreeNode* cur = root, *suc = nullptr; 
    while (cur) {
        if (cur->val > p->val) {
            suc = cur;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return suc;
}

// 附赠一个查找前驱
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* cur = root, *pre = nullptr;
    while (cur) {
        if (cur->val < p->val) {
            pre = cur;
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
}