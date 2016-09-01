// Sourse : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Difficulty : Hard

/***********************************************************************
 *
 * You are given an integer array nums and you have to return a new counts array. 
 * The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 *
 **********************************************************************/

class Solution {
private:
    // まあ所以这个tree node里面存的是个什么了啦（手动斜眼
    // 每个node存的是arr(y, x]里面的smaller个数
    // 所谓的smaller也就是排序后index更小的数っという
    void update(vector<int>& tree, int i, int val) {
        while(i < tree.size()) {
            tree[i] += val; // 遍历child！
            i += (-i&i);
        }
    }
    int count (vector<int>& tree, int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (-i&i);
        }
        return sum;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) return res;
        int n = nums.size();
        res = vector<int>(n, 0);
        // copy and sort
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        // map<number, sorted_index>
        unordered_map<int, int> map;
        for (int i=0; i<n; i++) map[sorted[i]] = i;
        // binary indexed tree
        vector<int> tree = vector<int>(n+1, 0);
        // calc from the right end
        for(int i=n-1; i>=0; i--) {
            res[i] = count(tree, map[nums[i]]);
            update(tree, map[nums[i]] + 1, 1);
        }
        return res;
    }
};