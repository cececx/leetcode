// Sourse : https://leetcode.com/problems/permutations/
// Author : Cecilia Chen

// Difficulty : Medium

/***********************************************************************
 *
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * input:  [1,2,3]
 * output: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
 *
 **********************************************************************/
 
 
 
// nextPermutation: Amortized O(1)
// use nextPermutation to generate all permutation: O(n!)
class Solution1 {
public:
    vector<int> nextPermutation(vector<int> nums) {
        int i = nums.size() - 1, j = i;
        while (i >= 1 && nums[i] <= nums[i-1]) --i;
        while (j > i && nums[j] <= nums[i-1]) --j;
        if (i >= 1) swap(nums[i-1], nums[j]);
        reverse(nums.begin()+i, nums.end());
        return nums;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int size = 1;
        for (int i=2; i<=nums.size(); i++) size *= i;
        vector<vector<int>> res = {nums};
        for (int i=1; i<size; i++) {
            nums = nextPermutation(nums);
            res.push_back(nums);
        }
        return res;
    }
};




// Heap's Algorithm
class Solution2 {
public:
    void generate(int n, vector<int> arr, vector<vector<int>>& res) {
        if (n == arr.size())
            res.push_back(arr);
        else {
            for (int i=n; i<arr.size(); ++i) {
                swap(arr[i], arr[n]);
                generate(n + 1, arr, res);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        generate(0, nums, res);
        return res;
    }
};