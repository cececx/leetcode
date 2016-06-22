// Source : https://leetcode.com/problems/longest-increasing-subsequence/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an unsorted array of integers, 
 * find the length of longest increasing subsequence.
 *
 **********************************************************************/
 

// 88ms. Time O(n2), Space O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, m;
        vector<int> dp(n);
        for (int i=0; i<n; ++i) {
            m = 0;  // 加个tmp变量，节约O(n2)次dp[i]寻址 ╰(￣ω￣ｏ)
            for (int j=0; j<i; ++j)
                if (nums[j] < nums[i])
                    m = max(m, dp[j]);
            dp[i] = m + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};


// 4ms. Time O(nlogn), Space O(n)

/* 【参考】http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
    原帖算法是存长度不同的lists，保证每个list的elements都是最小的，像酱：
    [0]
    [0, 1]
    [0, 1, 3]
    [0, 1, 3, 7]
    [0, 2, 6, 9, 11]
    [0, 2, 6, 9, 11, 15]
    
    既然这群小妖精的尾号是递增的，我们就把它存成酱：
    [0, 1, 3, 7, 11, 15]
    
    完美，我真帅（x   */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, dp[n];  // 就是不爱用vector你咬我w
        for (int i=0; i<n; ++i) {
            auto it = lower_bound(dp, dp + res, nums[i]);
            if (it == &dp[res]) dp[res++] = nums[i];
            else *it = nums[i];
        }
        return res;
    }
};