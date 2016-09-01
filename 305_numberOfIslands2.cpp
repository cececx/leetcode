// Sourse : https://leetcode.com/problems/number-of-islands-ii/
// Difficulty : Hard

/***********************************************************************
 *
 * A 2d grid map of m rows and n columns is initially filled with water. 
 * We may perform an addLand operation which turns the water at position (row, col) into a land. 
 * Given a list of positions to operate, count the number of islands after each addLand operation. 
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water.
 *
 * Challenge:
 * Can you do it in time complexity O(k log mn), where k is the length of the positions?
 *
 **********************************************************************/

// Union-Find
// 原来它叫作Weighted Quick Union-Find with Path Compression哈哈哈拍桌

class Solution {
private:
    const int delta[5] = {0, 1, 0, -1, 0};
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UnionFind uf(m * n);
        int waterCount = m * n;
        vector<int> res;
        vector<vector<bool>> lands(m, vector<bool>(n, 0));
        for (auto pos : positions) {
            int y = pos.first, x = pos.second;
            if (lands[y][x]) continue;
            if (y > 0 && lands[y-1][x]) uf.join(y*n+x, (y-1)*n+x);
            if (x > 0 && lands[y][x-1]) uf.join(y*n+x, y*n+x-1);
            if (y < m-1 && lands[y+1][x]) uf.join(y*n+x, (y+1)*n+x);
            if (x < n-1 && lands[y][x+1]) uf.join(y*n+x, y*n+x+1);
            lands[y][x] = 1;
            res.push_back(uf.count() - (--waterCount));
        }
        return res;
    }
};

class UnionFind {
private:
    int counter = 0; // number of sets
    vector<int> sz; // size of current set
    vector<int> id; // root index of current set
public:
    UnionFind(int n) : counter(n), sz(n, 1), id(n) {
        for (int i = 0; i < n; i++) id[i] = i;
    }
    int root(int i) {
        // if id[i] is not the root, update id[i]
        while (id[i] != i) {
            id[i] = id[id[i]]; // change <root of i> to <root of root of i> wwww
            i = id[i]; // go to <root of i>
        }
        return i;
    }
    void join(int i, int j) {
        int a = root(i), b = root(j);
        if (a != b) { // join a (smaller) into b (larger)
            if (sz[a] > sz[b]) swap(a, b);
            id[a] = b;
            sz[b] += sz[a];
            --counter;
        }
    }
    bool connected(int i, int j) {
        return root(i) == root(j);
    }
    int count() {
        return counter;
    }
};

