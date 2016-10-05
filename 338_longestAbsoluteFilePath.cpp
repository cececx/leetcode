// Sourse : https://leetcode.com/problems/longest-absolute-file-path/
// Difficulty : Medium

/***********************************************************************
 *
 * Indent: '\t'
 * Require: longest length of path
 * 
 **********************************************************************/
 
class Solution {
public:
    vector<string> split(const string &s, char delim) {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
            res.push_back(item);
        return res;
    }
    
    bool isFile(string name) {
        return name.find_first_of('.') != -1;
    }
    
    void DFS(vector<string>& lines, int& max_len, int cur_depth, int cur_len, int cur_index) {
        if (cur_index >= 0 && isFile(lines[cur_index])) {
            max_len = max(max_len, cur_len - 1);
            return;
        }
        for (int i = cur_index + 1; i < lines.size(); i++) {
            int d = lines[i].find_first_not_of('\t');
            if (d > cur_depth + 1) continue;
            if (d <= cur_depth) break;
            int filename_len = lines[i].size() - d;
            DFS(lines, max_len, cur_depth + 1, cur_len + filename_len + 1, i);
        }
    }
    
    int lengthLongestPath(string input) {
        vector<string> lines = split(input, '\n');
        lines.insert(lines.begin(), "");
        int res = 0;
        DFS(lines, res, -1, 0, 0);
        return res;
    }
};