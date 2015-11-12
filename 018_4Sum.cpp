// Sourse : https://leetcode.com/problems/4sum/
// Author : Cecilia Chen
// Date   : 2015-11-12

/***********************************************************************
 *
 * Given an array S of n integers,
 * are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *
 **********************************************************************/
 
class Solution {
public:
    // Solution: 4Sum = n * 3sum = n * n * 2sum
    // Optimization: add boundary conditions, runtime: 128ms -> 16ms
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        // 4Sum
        for(int a=0; a<n-3; ++a) {
            if (a>0 && nums[a]==nums[a-1]) continue;
            if (nums[a] + nums[a+1] + nums[a+2] + nums[a+3] > target) break;
            if (nums[a] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            // 3Sum
            for(int b=a+1; b<n-2; ++b) {
                if (b>a+1 && nums[b]==nums[b-1]) continue;
                if (nums[a] + nums[b] + nums[b+1] + nums[b+2] > target) break;
                if (nums[a] + nums[b] + nums[n-1] + nums[n-2] < target) continue;
                // 2Sum
                int c = b+1, d = n-1;
                while (c < d) {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum < target) { ++c; continue; }
                    if (sum > target) { --d; continue; }
                    ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                    do { ++c; } while (nums[c] == nums[c-1]);
                    do { --d; } while (nums[d] == nums[d+1]);
                }
            }
        }
        return ans;
    }
};
