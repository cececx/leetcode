# [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)
Difficulty: **Medium**

>Given a 2d grid map of `'1'`s (land) and `'0'`s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

> **Answer:** 3
```
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
```
**Answer:** 3
```
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
```

### Solutions
哎呀呀这道题没做过，姑且来随便口胡一下。
* 最简单当然是从一个1开始DFS，把周围的所有1都标成x.
* 遇到不是1，要么是水要么已经标记过了，所以跳过。
* 每遇到一块儿1，计数器加一.
* 简直是流氓会武术hhhhh
* BruteForce结果似乎是O(n)，并不很相信……

说着，PO主思考了一下。之所以用BFS，是因为，如果顺序遍历的话：
* 同一行的两个1不相连，所以标记为不同颜色.
* 到了下一行发现它们竟然相连了，怎么合并在一起呢.
* 于是PO主一拍脑袋，妈呀这不Union-Find吗.
* UnionFind的结果是O(n)

### DFS Solution

我又BruteForce了（捂住了双眼

```c++
void DFS(vector<vector<char>>& grid, int x, int y, int m, int n) {
    if (grid[y][x] != '1') return;
    grid[y][x] = 'x';
    if (x-1 >= 0) DFS(grid, x-1, y, m, n);
    if (x+1 < m)  DFS(grid, x+1, y, m, n);
    if (y-1 >= 0) DFS(grid, x, y-1, m, n);
    if (y+1 < n)  DFS(grid, x, y+1, m, n);
}
int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int n = grid.size(), m = grid[0].size(), count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '1') {
                count++;
                DFS(grid, j, i, m, n);
            }
    return count;
}
```

### Union-Find Solution

Union-Find implementation:

```C++
class UnionFind
{
private:
    int counter;      // number of sets
    vector<int> id;   // root of the k-th node
    vector<int> sz;   // size of union contains the k-th node

public:
    UnionFind(int n) :id(n), sz(n, 1), counter(n) {
        for (int i = 0; i < n; ++i) {
            id[i] = i;  // init: node.root = node
        }
    }

    int root(int i) { // get root of node i
        while (i != id[i]) {     // if node.root is not itself
            id[i] = id[id[i]];   // update: node.root = node.root.root
            i = id[i];           // goto node.root
        }
        return i;
    }

    void uni(int p, int q) { 
        int i = root(p);
        int j = root(q);
        if (i != j) { // if not in the same set
            if (sz[i] < sz[j]) {
                swap(i, j); // make sure set-i > set-j
            }
            id[j] = i;      // join the smaller set into the bigger set
            sz[i] += sz[j];
            --counter;
        }
    }

    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    int count() {
        return counter;
    }
};
```
Solution:
```c++
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size(), zeros = 0;
        UnionFind uf(m*n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') { // connect every 1 with right 1 and beneath 1
                    if (i < n-1 && grid[i+1][j] == '1') {
                        uf.uni(i*m + j, (i+1)*m + j);
                    }
                    if (j < m-1 && grid[i][j+1] == '1') {
                        uf.uni(i*m + j, i*m + j + 1);
                    }
                }
                else {
                    zeros ++; // count zeros (separate sets)
                }
            }
        }
        return uf.count() - zeros;
    }
};
```