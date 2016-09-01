// Sourse: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Difficulty : Medium

/***********************************************************************
 *
 * Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 **********************************************************************/

/*

Solution 1: Sort O(nlogn)

Solution 2: MaxHeap O(n + klogn)
 * Build O(n)
 * Pop O(logn)
 
Solution 3: MinHeap O(k + (n-k)logk)
 * Build O(k)
 * Push/Pop O(logn)
 
Solution 4: QuickSelect O(n)

*/ 
 
// Quick select: O(n)
class Solution {
public:
    void setMedian(vector<int>& nums, int left, int right) {
        int l = left, r = right-1, m = (right + left) >> 1;
        if (nums[l] > nums[m]) swap(nums[l], nums[m]);
        if (nums[m] > nums[r]) swap(nums[m], nums[r]);
        if (nums[l] < nums[m]) swap(nums[l], nums[m]);
    }
    
    // 我们来把大的排在左边吧嘻嘻[left, right)
    int partition(vector<int>& nums, int left, int right) {
        setMedian(nums, left, right);
        int pivot = nums[left], i = left;
        // 降序排列，i标记的是最后一个比pivot大的
        for (int j = left + 1; j < right; j++)
            if (nums[j] > pivot)
                swap(nums[++i], nums[j]);
        swap(nums[left], nums[i]);
        return i;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size();
        while (right - left > 1) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos;
            else left = pos + 1;
        }
        return nums[left];
    }
};