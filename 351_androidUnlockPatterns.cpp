// Sourse : https://leetcode.com/problems/android-unlock-patterns/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, 
 * count the total number of unlock patterns of the Android lock screen, 
 * which consist of minimum of m keys and maximum n keys.
 *
 **********************************************************************/

// backtracking的话ヽ(●´ω｀●)
// 因为格子是中心对称的，所以 <从1出发> * 4 + <从2出发> * 4 + <从5出发>
class Solution {
private:
    vector<vector<int>> jumps;
    int getMid(int a, int b) {
        if (a > b) swap(a, b);
        return jumps[a-1][b-1];
    }
    /**
     * @param visited   Visited num in current path
     * @param cur       Current num
     * @return Number of paths starts from current num
     */
    int DFS(bool* visited, int len, int cur, int minSize, int maxSize) {
        int res = 0;
        if (len > maxSize) return res;
        if (len >= minSize) res++;
        visited[cur] = 1;
        for (int next = 1; next < 10; next++) {
            if (visited[next]) continue;
            int midNum = getMid(cur, next);
            if (midNum && !visited[midNum]) continue;
            res += DFS(visited, len + 1, next, minSize, maxSize); 
        }
        visited[cur] = 0;
        return res;
    }
public:
    int numberOfPatterns(int m, int n) {
        jumps = vector<vector<int>>(9, vector<int>(9, 0));
        jumps[0][2] = 2; jumps[3][5] = 5; jumps[6][8] = 8; jumps[0][6] = 4; 
        jumps[1][7] = 5; jumps[2][8] = 6; jumps[0][8] = 5; jumps[2][6] = 5;
        bool visited[10] = {0};
        return DFS(visited, 1, 1, m, n) * 4
             + DFS(visited, 1, 2, m, n) * 4
             + DFS(visited, 1, 5, m, n);
    }
};