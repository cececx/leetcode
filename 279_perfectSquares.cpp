// Source : https://leetcode.com/problems/perfect-squares/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a positive integer n, find the least number of perfect square numbers which sum to n.
 *
 **********************************************************************/

 
// 256ms. DP. Time O(n * sqr(n)), Space O(n)
class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1] = {0};
        fill(dp+1, dp+n+1, (int)INT_MAX);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j*j <= i; ++j)
                dp[i] = min(dp[i], dp[i-j*j] + 1);
        return dp[n];
    }
};



// ---------------------------------------------------------------



// 64ms. BFS. Time O(sqr(n)), Space O(n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares; // record all square numbers 
        bool visited[n] = {0}; // num[i-1] = #sum to i
        queue<int> q; // queue for BST
        int tmp = 1;
        for (int i=2; tmp <= n; ++i) { // initialize
            squares.push_back(tmp);
            visited[tmp-1] = 1;
            q.push(tmp);
            tmp = i * i;
        }
        if (squares.back() == n) return 1; // check if n is a square
        int depth = 1;
        while (!q.empty()) { // BFS
            ++ depth;
            int size = q.size();
            while (size --) {
                int node = q.front();
                q.pop();
                for (int square : squares) { // next_node = current_node + some_square
                    tmp = node + square;
                    if (tmp == n) return depth;
                    if (tmp > n) break;
                    if (!visited[tmp - 1]) {
                        visited[tmp - 1] = 1;
                        q.push(tmp);
                    }
                }
            }
        }
        return 0;
    }
};
