// Sourse : https://leetcode.com/problems/zigzag-iterator/
// Difficulty : Medium

/***********************************************************************
 *
 * Given two 1d vectors, implement an iterator to return their elements alternately.
 * 
 * For example, given two 1d vectors:
 * 
 * v1 = [1, 2]
 * v2 = [3, 4, 5, 6]
 * By calling next repeatedly until hasNext returns false, 
 * the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
 * 
 * Follow up: What if you are given k 1d vectors?
 * How well can your code be extended to such cases?
 * 
 * Clarification for the follow up question - Update (2015-09-18):
 * The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:
 * 
 * [1,2,3]
 * [4,5,6,7]
 * [8,9]
 * It should return [1,4,8,2,5,9,3,6,7].
 * 
 **********************************************************************/
 
 
// 过于简单了都不想写hhhh
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        n = v1.size() + v2.size();
        v = vector<int>(n);
        int i = 0, j = 0;
        while (i < v1.size() && i < v2.size()) {
            v[j++] = v1[i];
            v[j++] = v2[i++];
        }
        while (i < v1.size()) {
            v[j++] = v1[i++];
        }
        while (i < v2.size()) {
            v[j++] = v2[i++];
        }
    }

    int next() {
        return v[index++];
    }

    bool hasNext() {
        return index < n;
    }
    
private:
    vector<int> v;
    int n, index = 0;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */