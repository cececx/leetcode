// Sourse : https://leetcode.com/problems/walls-and-gates/
// Difficulty : Medium

/***********************************************************************
 *
 * You are given a m x n 2D grid initialized with these three possible values.
 * 
 * -1 - A wall or an obstacle.
 * 0 - A gate.
 * INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
 * Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
 * 
 * For example, given the 2D grid:
 * INF  -1  0  INF
 * INF INF INF  -1
 * INF  -1 INF  -1
 *   0  -1 INF INF
 * After running your function, the 2D grid should be:
 *   3  -1   0   1
 *   2   2   1  -1
 *   1  -1   2  -1
 *   0  -1   3   4
 *
 **********************************************************************/

// 应该可以借助前面已经更新过的
// 或者说，在BFS一个格子的时候就更新最短的那条路径？好像有些难
// 所以既然是多源最短路径，仿照Dijkstra做DFS就好了，从0的位置开始做
class Solution {
private:
    int n, m;
    void DFS(vector<vector<int>>& rooms, int step, int i, int j) {
        step += 1;
        // up
        if (i > 0 && rooms[i-1][j] > step) {
            rooms[i-1][j] = step;
            DFS(rooms, step, i-1, j);
        }
        // left
        if (j > 0 && rooms[i][j-1] > step) {
            rooms[i][j-1] = step;
            DFS(rooms, step, i, j-1);
        }
        // right
        if (j < m - 1 && rooms[i][j+1] > step) {
            rooms[i][j+1] = step;
            DFS(rooms, step, i, j+1);
        }
        // down
        if (i < n - 1 && rooms[i+1][j] > step) {
            rooms[i+1][j] = step;
            DFS(rooms, step, i+1, j);
        }
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;
        n = rooms.size(), m = rooms[0].size();
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (!rooms[i][j])
                    DFS(rooms, 0, i, j);
    }
};