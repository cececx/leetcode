// Source : https://leetcode.com/problems/h-index-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * Follow up for H-Index: What if the citations array is sorted in ascending order? 
 * Could you optimize your algorithm?
 *
 **********************************************************************/

// BinarySearch. Time O(logn), Space O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (citations[mid] < n-mid) l = mid + 1;
            else r = mid;
        }
        return n - l;
    }
};
