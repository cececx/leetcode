// Sourse : https://leetcode.com/problems/contains-duplicate/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 *
 **********************************************************************/
 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto num : nums) {
            if (set.find(num) != set.end()) return true;
            else set.insert(num);
        }
        return false;
    }
};