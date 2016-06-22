// Source: https://leetcode.com/problems/max-points-on-a-line/
// Difficulty: Hard

/***********************************************************************
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 *
 **********************************************************************/
 
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

 
 
// 嘻嘻 说先brute force试试看 一遍AC击败了97.79%的小伙伴


// 12ms, Time O(n2), Space O(n2)
class Solution {
public:
    bool isEqual(Point a, Point b) { return a.x == b.x && a.y == b.y; }
    
    int maxPoints(vector<Point>& points) {
        int n = points.size(), res = 0;
        if (n < 2) return n;

        // start from each point
        for (int i = 0; i < n - 1; ++i) {
            vector<float> K;
            int cnt = 0;
            
            // connect to other points
            for (int j = i + 1; j < n; ++j) {
                if (isEqual(points[i], points[j])) ++cnt;
                else K.push_back(points[i].y == points[j].y ? INFINITY : (points[i].x-points[j].x) / ((double) (points[i].y - points[j].y)));
            }
            
            // get max points
            sort(K.begin(), K.end());
            int first = 0, m = K.size();
            while (first < m) {
                int last = first;
                while (last < m - 1 && K[last] == K[last + 1]) ++last;
                res = max(res, last - first + 2 + cnt);
                first = last + 1;
            }
            if (!m) res = max(res, cnt + 1);
        }
        return res;
    }
};





// 既然这样我们来试试HashTable吧嘻嘻
// 我就知道hashtable慢得一比哼哼

// 24ms, Time O(n2), Space O(n2)
class Solution {
public:
    bool isEqual(Point a, Point b) { return a.x == b.x && a.y == b.y; }
    
    int maxPoints(vector<Point>& points) {
        int n = points.size(), res = 0;
        if (n < 2) return n;
        
        for (int i = 0; i < n - 1; ++i) {
            unordered_map<float, int> K;
            int cnt = 1;
            for (int j = i + 1; j < n; ++j) {
                if (isEqual(points[i], points[j])) ++cnt;
                else ++ K[points[i].y == points[j].y ? INFINITY : ((points[i].x - points[j].x) / ((double) (points[i].y - points[j].y)))];
            }
            
            for (auto it : K) res = max(res, it.second + cnt);
            if  (K.empty())   res = max(res, cnt);
        }
        return res;
    }
};
