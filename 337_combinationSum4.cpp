// Sourse : https://leetcode.com/problems/combination-sum-iv/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an integer array with all positive numbers and no duplicates, 
 * find the number of possible combinations that add up to a positive integer target.
 *
 **********************************************************************/
 
// 都是正数什么的，backtracking？只需要统计次数的backtracking果然还是DP吧
// DP[i]表示i的拼法？重复的部分怎么办呢……有重复吗_(:3TZ)_
// 比如说 5 = 1 + 4(1+1+1+1) = 2 + 3(1+1+1) 果然没有重复啊！

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> sums(target + 1, 0);
        sums[0] = 1;
        for (int i = 1; i < target + 1; i++)
            for (int x : nums)
                if (x <= i)
                    sums[i] += sums[i - x];
        return sums[target];
    }
};