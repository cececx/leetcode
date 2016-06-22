// Source : https://leetcode.com/problems/majority-element/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 **********************************************************************/

// Time O(n), Space O(n) 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int size = nums.size();
        for(int i=0; i<size; ++i) {
            ++ map[nums[i]];
            if (map[nums[i]] > size/2 ) return nums[i];
        }
    }
}
	
// Time O(n), Space O(1)
class Solution {
public:
	int majorityElement(vector<int>& nums) {
        int res = nums[0], count = 1;
        for(int n : nums){
            if(!count){
                count++;
                res = n;
            }
            else res == n ? ++count : --count;
        }
        return res;
    }
};