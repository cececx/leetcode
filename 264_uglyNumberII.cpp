// Sourse : https://leetcode.com/problems/ugly-number-ii/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Write a program to find the n-th ugly number.
 *
 **********************************************************************/	
 
class Solution {
private:
    int Min(int a, int b, int c) {
        int tmp = a < b ? a : b;
        return tmp < c ? tmp : c;
    }
    
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        int* nums = new int[n];
        nums[0] = 1;
        int i(1), index2(0), index3(0), index5(0);
        while (i < n) {
            int val = Min(nums[index2]*2, nums[index3]*3, nums[index5]*5);
            index2 += val == (nums[index2]*2);
            index3 += val == (nums[index3]*3);
            index5 += val == (nums[index5]*5);
            nums[i++] = val;
        }
        int ans = nums[n-1];
        delete[] nums;
        return ans;
    }
};