// Sourse : https://leetcode.com/problems/majority-element/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 **********************************************************************/
 
class Solution {
public:
    // #define hashmap
    #ifdef hashmap

    // 48ms, hash map
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int size = nums.size();
        for(int i=0; i<size; ++i) {
            if (map.find(nums[i])==map.end())
                map[nums[i]] = 0;
            ++ map[nums[i]];
            if (map[nums[i]] > size/2 ) return nums[i];
        }
    }
	
    #else
		
	// 12ms
	int majorityElement(vector<int>& nums) {
        int major=nums[0], count = 1;
        for(int i=1; i<nums.size();i++){
            if(count == 0){
                count++;
                major=nums[i];
            }
            else if(major==nums[i]) count++;
            else count--;
        }
        return major;
    }
	
    #endif
};