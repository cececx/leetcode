// Sourse : https://leetcode.com/problems/unique-binary-search-trees/
// Difficulty : Medium

/***********************************************************************
 *
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 **********************************************************************/

class Solution {
public:
    int numTrees(int n) {
        vector<int> b(n+1, 0);  // b[i]: #BST with value 1...i
        b[0] = 1;
        for(int i=1; i<n+1; ++i) #nodes, 1 ~ n
            for(int left = 0; left <= i-1; ++left) // #nodes in left tree
                b[i] += b[left] * b[i-1-left];
        return b[n];
    }
    
    // DP已是随手一写（我好帅ヽ(●´ω｀●)
};