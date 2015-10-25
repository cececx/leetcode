// Sourse : https://leetcode.com/problems/two-sum/
// Author : Cecilia Chen
// Date   : 2015-10-23

/***********************************************************************
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. 
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 **********************************************************************/

class Solution {
public:
	// 12ms
	vector<int> twoSum(vector<int>& nums, int target) {
		// sort
		vector<int> temp(nums.begin(), nums.end());
		sort(temp.begin(), temp.end()); // O(nlogn)
		// two pointers
		int i = 0, j = nums.size() - 1;
		while (i<j) {
			int sum = temp[i] + temp[j];
			if (sum == target) break;
			if (sum < target) ++i; else --j;
		}
		// find result
		vector<int> ret;
		int num1 = temp[i], num2 = temp[j];
		for (int k = 0; k<nums.size(); k++) {
			if (num1 == nums[k] || num2 == nums[k]) {
				ret.push_back(++k); 
				break;
			}
		}
		for (int k = ret[0]; k<nums.size(); k++) {
			if (num1 == nums[k] || num2 == nums[k]) { 
				ret.push_back(++k); 
				break;
			}
		}
		return ret;
	}
};
