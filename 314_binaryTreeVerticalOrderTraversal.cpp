// Source : https://leetcode.com/problems/binary-tree-vertical-order-traversal/
// Difficulty: Medium

/***********************************************************************
 *
 * Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
 * 
 * If two nodes are in the same row and column, the order should be from left to right.
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

// Time O(n)
// 就用deque就不用map你咬我呀w  map难道不是O(nlogn)吗
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        deque<vector<int>> res;
        int leftMost = 0;
        queue<pair<TreeNode*, int>> q({{root, 0}});
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                TreeNode* cur = q.front().first;
                int index = q.front().second;
                q.pop();
                if (cur) {
                    while (index < leftMost) {
                        leftMost--;
                        res.push_front(vector<int>());
                    }
                    while (index - leftMost >= res.size())
                        res.push_back(vector<int>());
                    res[index-leftMost].push_back(cur->val);
                    q.emplace(cur->left, index-1);
                    q.emplace(cur->right, index+1);
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};