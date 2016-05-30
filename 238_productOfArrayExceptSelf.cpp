// Sourse : https://leetcode.com/problems/product-of-array-except-self/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an array of n integers where n > 1, nums, 
 * return an array output such that 
 * output[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * Solve it without division and in O(n) Time.
 * Solve it in O(1) Space
 * 
 **********************************************************************/
 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // left part of nums[i]
        for (int i=1; i<n; ++i)
            ans[i] = ans[i-1] * nums[i-1];
            
        // right part of nums[i]
        int prod = 1;
        for (int i=n-1; i>=0; --i) {
            ans[i] *= prod;
            prod *= nums[i];
        }
        
        return ans;
    }
};