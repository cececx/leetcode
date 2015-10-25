class Solution {
public:
	// O(log(m+n)), 44ms
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int a = 0, b = 0, m = nums1.size(), n = nums2.size();
		int target = (m + n - 1) >> 1;
		int mid;
		while (a<m && b<n && (a + b) <= target)
			mid = nums1[a] < nums2[b] ? nums1[a++] : nums2[b++];
		while ((a + b) <= target) {
			mid = a<m ? nums1[a++] : nums2[b++];
		}
		if (!((m + n) % 2)) {
			if (a<m && b<n) mid += nums1[a] < nums2[b] ? nums1[a++] : nums2[b++];
			else mid += a < m ? nums1[a++] : nums2[b++];
			return mid / (double)2;
		}
		return mid;
	}
};