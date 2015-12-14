// Sourse : https://leetcode.com/problems/contains-duplicate-ii/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
 * such that nums[i] = nums[j] and the difference between i and j is at most k.
 *
 **********************************************************************/
 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k<=0) return false;
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); ++i) {
            auto it = map.find(nums[i]);
            if (it != map.end() && i-it->second <= k) return true;
            map[nums[i]] = i;
        }
        return false;
    }
};