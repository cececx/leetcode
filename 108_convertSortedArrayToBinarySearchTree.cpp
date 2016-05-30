// Sourse : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an array where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
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
    TreeNode* getNode(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        int mid = (l + r) >> 1;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = getNode(nums, l, mid-1);
        cur->right = getNode(nums, mid+1, r);
        return cur;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getNode(nums, 0, nums.size()-1);
    }
    
    // 哼哼哼随手一写就是AC我好帅
};