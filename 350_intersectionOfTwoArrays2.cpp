// Sourse : https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Difficulty : Easy

/***********************************************************************
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 *
 **********************************************************************/

// if the arrays are unsorted, use hashmap:
// Time O(n), Space O(1)
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int n : nums1)
            ++map[n];
        for (int n : nums2) {
            if (map.find(n) != map.end() && map[n] > 0) {
                res.push_back(n);
                --map[n];
            }
        }
        return res;
    }
};


// if the arrays are sorted:
// Time O(n), Space O(1)    
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { 
        vector<int> res;
        int i=0, j=0, len1=nums1.size(), len2=nums2.size();
        while (i < len1 && j < len2) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i++]);
                ++j;
            }
            else
                nums1[i] < nums2[j] ? ++i : ++j;
        }
        return res;
    }
};