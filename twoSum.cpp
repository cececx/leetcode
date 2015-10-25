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
			if (num1 == nums[k] || num2 == nums[k]) { ret.push_back(++k); break; }
		}
		for (int k = ret[0]; k<nums.size(); k++) {
			if (num1 == nums[k] || num2 == nums[k]) { ret.push_back(++k); break; }
		}
		return ret;
	}
};