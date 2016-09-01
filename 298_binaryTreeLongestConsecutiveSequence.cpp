// Source : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// Difficulty: Medium

/***********************************************************************
 *
 * Given a binary tree, find the length of the longest consecutive sequence path.
 * 
 * The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
 * The longest consecutive path need to be from parent to child (cannot be the reverse).
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
 
// 哼哼每个节点往下找不就好了，返回当前节点的最长length
// 判断左孩子和右孩子是否是连续的，否则返回当前节点1
// 还要记录最大值_(:3TZ)_
// 反正是个bottom-up solution

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        findLength(root, res);
        return res;
    }

    int findLength(TreeNode* node, int& maxLength) {
        if (!node) return 0;
        int leftLen = findLength(node->left, maxLength);
        int rightLen = findLength(node->right, maxLength);
        int len = max(node->left && node->val + 1 == node->left->val ? leftLen : 0,
                      node->right && node->val + 1 == node->right->val ? rightLen : 0) + 1;
        maxLength = max(len, maxLength);
        return len;
    }
};

// 来吧我们来做个top-down的╰(￣ω￣ｏ)
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        findLength(root, nullptr, 0, res);
        return res;
    }

    void findLength(TreeNode* node, TreeNode* parent, int pre, int& maxLen) {
        if (!node) return;
        int cur = 1 + (parent && parent->val + 1 == node->val ? pre : 0); // 运算符优先级啊少女w 教会了我们白板不要一行写太长
        maxLen = max(cur, maxLen);
        findLength(node->left, node, cur, maxLen);
        findLength(node->right, node, cur, maxLen);
    }
};