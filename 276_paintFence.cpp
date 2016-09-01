// Sourse : https://leetcode.com/problems/strobogrammatic-number-ii/
// Difficulty : Medium

/***********************************************************************
 *
 * There is a fence with n posts, each post can be painted with one of the k colors.
 *
 * You have to paint all the posts such that no more than two adjacent fence posts have the same color.
 *
 * Return the total number of ways you can paint the fence.
 *
 **********************************************************************/

// 哭泣了整个把题读错了啦TAT 最多有相邻两个木棍有相同颜色，而且每个木棍只能涂一种颜色啦八嘎！！！
// 那就存一个S表示和前一个颜色相同的涂法个数，D表示和前面不同的个数
// Recursion:
// * 如果和前面相同的话，前面那个必须和再前面不同，就是S[n] = D[n-1]
// * 如果和前面不同的话有多少种呢就是k-1种颜色乘以上一个棍子的颜色总和，D[n] = (k-1) * (S[n-1] + D[n-1])
// Base:
// * n = 0: return 0
// * n = 1: return k
// * 因此我们从n = 2开始做起，此时S/D分别表示第二个和第一个相同/不同的个数：S = k, D = k * (k - 1).

// Time O(n), Space O(1)
class Solution {
public:
    int numWays(int n, int k) {
        if (!n || !k) return 0;
        if (n == 1) return k;
        int s = k, d = k * (k - 1);
        for (int i = 2; i < n; i++) {
            int tmp = d;
            d = (k - 1) * (s + d);
            s = tmp;
        }
        return s + d;
    }
};