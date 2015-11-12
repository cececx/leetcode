// Sourse : https://leetcode.com/problems/3sum-closest/
// Author : Cecilia Chen
// Date   : 2015-11-12

/***********************************************************************
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers. 
 * You may assume that each input would have exactly one solution.
 *
 **********************************************************************/
 
class Solution {
public:
    // 12ms, O(n^2)
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int sum = nums[0]+nums[1]+nums[2];
        int gap = abs(target - sum);
        for (int a = 0; a < size-2; ++a) {
            int b = a+1, c = size-1;
            while (b < c) {
                int tmpSum = nums[a] + nums[b] + nums[c];
                int tmpGap = abs(target - tmpSum);
                if (tmpGap < gap) { sum = tmpSum; gap = tmpGap; }
                if (tmpSum < target) { ++b; continue; }
                if (tmpSum > target) { --c; continue; }
                return tmpSum;
            }
        }
        return sum;
    }
};
