// Sourse : https://leetcode.com/problems/range-sum-query-immutable/
// Difficulty : Easy

/***********************************************************************
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive
 *
 * 1. You may assume that the array does not change.
 * 2. There are many calls to sumRange function.
 *
 **********************************************************************/

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

class NumArray {
public:
    // maintain a sum[size+1], where sum[i] = sum(0, i-1), and sum[0] = 0;
    // so that required sum(i,j) = sum[j] - sum[i-1]
    NumArray(vector<int> &nums) {
        int size = nums.size();
        sums = vector<int>(size+1);
        sums[0] = 0;
        for(int i=0; i<size; ++i)
            sums[i+1] = sums[i] + nums[i];
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
    
private:
    vector<int> sums;
};