// https://leetcode.com/problems/number-of-islands/

// Union-Find solution

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