// Sourse : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Difficulty : Medium

/***********************************************************************
 *
 * Given the following perfect binary tree,
 * 
 *          1
 *        /  \
 *       2    3
 *      / \  / \
 *     4  5  6  7
 * 
 * After calling your function, the tree should look like:
 * 
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \  / \
 *     4->5->6->7 -> NULL
 * 
 **********************************************************************/
 
 /**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        linkChildren(root);
    }
    
    void linkChildren(TreeLinkNode* node) {
        if (!node || !node->left || !node->right) return;
        node->left->next = node->right;
        linkBetween(node->left, node->right);
        linkChildren(node->left);
        linkChildren(node->right);
    }
    
    void linkBetween(TreeLinkNode* leftParent, TreeLinkNode* rightParent) {
        if (!leftParent || !rightParent || !leftParent->left || !rightParent->left) return;
        leftParent->right->next = rightParent->left;
        linkBetween(leftParent->right, rightParent->left);
    }
};