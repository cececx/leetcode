// Sourse : https://leetcode.com/problems/two-sum/
// Author : Cecilia Chen
// Date   : 2015-10-23

/***********************************************************************
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. 
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 **********************************************************************/

class Solution {
public:
    // 16ms, Time Complexity O(n), Space Complexity O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); ++i) {
            if(hash.find( target-nums[i] ) != hash.end())
                return {hash[ target-nums[i] ] + 1, i + 1};
            hash[ nums[i] ] = i;
        }
        return {-1, -1};
    }
};
