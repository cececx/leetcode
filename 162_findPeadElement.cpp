// Source : https://leetcode.com/problems/find-peak-element/
// Difficulty : Medium

/***********************************************************************
 *
 * A peak element is an element that is greater than its neighbors.
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that num[-1] = num[n] = -∞.
 *
 **********************************************************************/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > max(nums[mid-1], nums[mid+1])) return mid - 1;
            if (nums[mid] < nums[mid+1]) l = mid + 1;
            else if (nums[mid] <= nums[mid-1]) r = mid - 1;
        }
        return max(0, l - 1);
    }
};
