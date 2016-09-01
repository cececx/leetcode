// https://leetcode.com/problems/the-skyline-problem/
// Difficulty : Hard

/***********************************************************************
 *
 * ...
 *
 **********************************************************************/

// Sweep-line + RBT
// 1. 按照x排序，进入h是正数，离开h是负数
// 2. 用multiset来存当前x位置对应的所有高度
// 3. 仅当当前最大高度和vec.back()不相等时，插入

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // sort by x-coord
        multimap<int, int> endpoints;
        for(auto b : buildings) {
            endpoints.emplace(b[0], b[2]);
            endpoints.emplace(b[1], -b[2]);
        }
        multiset<int> heights({0});
        vector<pair<int, int>> res;
        for(auto it = endpoints.begin(); it != endpoints.end();) {
            int x = it->first; // handle all points in the same x-coord
            do {
                int h = it->second;
                if (h > 0) heights.insert(h);
                else heights.erase(heights.find(-h));
                it++;
            } while(it != endpoints.end() && it->first == x);
            // check current max height
            int mh = *(heights.rbegin());
            if (res.empty() || mh != res.back().second) res.emplace_back(x, mh);
        }
        return res;
    }
};