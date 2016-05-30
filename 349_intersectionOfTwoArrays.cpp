// Sourse : https://leetcode.com/problems/intersection-of-two-arrays/
// Difficulty : Easy

/***********************************************************************
 *
 * Given two arrays, write a function to compute their intersection.
 * Each element int the result must be unique.
 *
 **********************************************************************/

 
// Hashset. time O(n), space O(n)
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> res;
        for (int n : nums2) 
            if (set.erase(n))
                res.push_back(n);
        return res;
    }
};



// Sort. Time (nlogn), space O(1)
class Solution2 {
public:  
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0, len1=nums1.size(), len2=nums2.size();
        while(i < len1 && j < len2) {
            while (i+1 < len1 && nums1[i+1] == nums1[i])  ++i;
            while (j+1 < len2 && nums2[j+1] == nums2[j])  ++j;
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            }
            else
                nums1[i] < nums2[j] ? ++i : ++j;
        }
        return res;
    }
};



// STL. Time O(nlogn), space O(1)
class Solution3 {
public:  
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(res));
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};