// Sourse : https://leetcode.com/problems/rectangle-area/
// Difficulty : Easy

/***********************************************************************
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 **********************************************************************/
 
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int t1 = max(D, B), b1 = min(D, B), l1 = min(A, C), r1 = max(A, C);
        int t2 = max(H, F), b2 = min(H, F), l2 = min(E, G), r2 = max(E, G);
        int h = (b1 >= t2 || b2 >= t1) ? 0 : min(t1, t2) - max(b1, b2);
        int w = (l1 >= r2 || l2 >= r1) ? 0 : w = min(r1, r2) - max(l1, l2);
        return (t1 - b1) * (r1 - l1) + (t2 - b2) * (r2 - l2) - h * w;
    }
};