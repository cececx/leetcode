// Sourse : https://leetcode.com/problems/3sum/
// Author : Cecilia Chen
// Date   : 2015-10-29

/***********************************************************************
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *
 **********************************************************************/

class Solution {
public:

    // Complexity for K-Sum problem is O(N^ceil(k/2))
    // For 3-Sum, the lower bound is O(N2)
	 
	 
    // 52ms, O(N2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; nums[i] <= 0; i++) {
            int j = i+1; int k = nums.size()-1;
            while (j < k) {
                int a = nums[i], b = nums[j], c = nums[k];
                if (a+b+c > 0) --k;
                else if (a+b+c < 0) ++j;
                else {
                    ans.push_back({a, b, c});
                    while (nums[j] == b) ++j;
                    while (nums[k] == c) --k;
                }
            }
            while (nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};