// Sourse : https://leetcode.com/problems/n-queens/
// Difficulty : Hard

/***********************************************************************
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens' placement, 
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 
 **********************************************************************/

// 这种喵小朋友随手hardcode就AC的你也好意思说是hard
// 12ms
class Solution {
private:
    bool check(vector<string>& current, int y, int x, int n) {
        for (int i=0; i<y; i++) if (current[i][x]=='Q') return false;
        for (int i=0; i<n; i++) if (current[y][i]=='Q') return false;
        for (int i=0; x-i>=0 && y-i>=0; i++) if (current[y-i][x-i]=='Q') return false;
        for (int i=0; x+i<n  && y-i>=0; i++) if (current[y-i][x+i]=='Q') return false;
        return true;
    } 
    void backtrack(vector<vector<string>>& res, vector<string>& current, int line, int n) {
        if (line == n) {
            res.push_back(current);
            return;
        }
        for (int i=0; i<n; i++) {
            if (!check(current, line, i, n)) continue;
            current[line][i] = 'Q';
            backtrack(res, current, y+1, n);
            current[line][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (!n) return vector<vector<string>>();
        vector<vector<string>> res;
        vector<string> cur(n, string(n, '.'));
        backtrack(res, cur, 0, n);
        return res;
    }
};


// Solution2: 4ms
// 嘻嘻听说计算机君能解决的极限是27Queen那我们就不要客气地用int吧
class Solution {
private:
    /**
     * @param res    Result
     * @param cur    Current solution
     * @param line   Index of current line
     * @param n      Size
     * @param c      Column flag
     * @param l      Left diagonals flag
     * @param r      Right diagonals flag
     */
    void backtrack(vector<vector<string>>& res, vector<string>& cur, int line, int n, int c, int l, int r) {
        if (line == n) {
            res.push_back(cur);
            return;
        }
        for (int i=0; i<n; i++) {
            if (c&(1 << i) || l&(1 << (i-line+n-1)) || r&(1 << (i+line))) continue;
            cur[line][i] = 'Q';
            backtrack(res, cur, line + 1, n, c|(1 << i), l|(1 << (i-line+n-1)), r|(1 << (i+line)));
            cur[line][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (!n) return vector<vector<string>>();
        vector<vector<string>> res;
        vector<string> cur(n, string(n, '.'));
        backtrack(res, cur, 0, n, 0, 0, 0);
        return res;
    }
};
