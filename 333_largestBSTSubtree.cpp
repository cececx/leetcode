// Sourse : https://leetcode.com/problems/largest-bst-subtree/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), 
 * where largest means subtree with largest number of nodes in it.
 *
 * Follow Up: Solve it in O(n) time.
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

// Naive Solution 1:
// 判断当前节点是否为BST: O(n) 参考 098.ValidateBST
// 对于每个节点操作：O(n^2)


// Solution 2: Bottom-Up O(n)

// 为了保证孩子是BST，需要用&isBST, &MIN, &MAX存Bottom-Up的info，用于判断子树是否合法
// &count用来返回当前节点的最大BST子树，如果当前节点不合法，返回子节点的最大BST子树即可
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int count = 0, minValue = INT_MIN, maxValue = INT_MAX;
        bool isBST = false;
        largestBST(root, count, isBST, minValue, maxValue);
        return count;
    }
    
    void largestBST(TreeNode* node, int& count, bool& isBST, int& minValue, int& maxValue) {
        if (!node) return;
        
        // Recursively check children
        bool isBSTL = true, isBSTR = true;
        int minL = INT_MAX, minR = INT_MAX, maxL = INT_MIN, maxR = INT_MIN;
        int countL = 0, countR = 0;
        largestBST(node->left, countL, isBSTL, minL, maxL);
        largestBST(node->right, countR, isBSTR, minR, maxR);
        
        // valid BST
        if (isBSTL && isBSTR && maxL <= node->val && minR >= node->val) { 
            minValue = min(node->val, minL);
            maxValue = max(node->val, maxR);
            count = countL + countR + 1;
            isBST = true;
        }
        
        // invalid BST
        else {
            isBST = false;
            count = max(countL, countR);
        }
    }
};