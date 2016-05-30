// Sourse : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Difficulty: Medium

/***********************************************************************
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
 *
 **********************************************************************/

class Solution1 {
public:
	// O(m + n) 
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
		int a(0), b(0), t = (m + n - 1) >> 1, mid;
		while (a < m && b < n && (a + b) <= t)
			mid = nums1[a] < nums2[b] ? nums1[a++] : nums2[b++];
		while ((a + b) <= t)
			mid = a < m ? nums1[a++] : nums2[b++];
        if ((m + n) & 1) 
            return mid; // odd length
		if (a < m && b < n) 
            mid += nums1[a] < nums2[b] ? nums1[a++] : nums2[b++];
		else 
            mid += a < m ? nums1[a++] : nums2[b++];
		return mid / 2.0; // even length
	}
};

class Solution2 {
public:
    // O(log min(m,n))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size(), n = nums2.size();
    	if (m > n) return findMedianSortedArrays(nums2, nums1);
    	int l = 0, r = m, i, j, h = (m + n + 1) >> 1;
    	while (l <= r) {
    	    i = (l + r) >> 1;
    	    j = h - i;
    	    if (i > 0 && j < n && nums1[i-1] > nums2[j])       // left
                r = i - 1; 
    	    else if (j > 0 && i < m && nums2[j-1] > nums1[i])  // right
                l = i + 1; 
    	    else break;
    	}
    	int a = i && j ? max(nums1[i-1], nums2[j-1]) : i ? nums1[i-1] : nums2[j-1];
        if ((m + n) & 1) return a; // odd length
    	int b = i!=m && j!=n ? min(nums1[i], nums2[j]) : i!=m ? nums1[i] : nums2[j];
    	return (a + b) / 2.0; // even length
    }
};

/*  
  nums1: A[0] ~ A[i-1]  |  A[i] ~ A[m]
  nums2: B[0] ~ B[j-1]  |  B[j] ~ B[n]   

  ensure: 
    * i + j = (m + n) / 2 ---> j = (m + n) / 2 - i
    * A[i-1] <= B[j], B[j-1] <= A[i].

  mid --> max(A[i-1], B[j-1]) | min(A[i], B[j])
*/