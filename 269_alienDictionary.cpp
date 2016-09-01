// Sourse : https://leetcode.com/problems/alien-dictionary/
// Difficulty : Hard

/***********************************************************************
 *
 * There is a new alien language which uses the latin alphabet. 
 * However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
 * 
 * For example,
 * Given the following words in dictionary,
 * 
 * [
 *   "wrt",
 *   "wrf",
 *   "er",
 *   "ett",
 *   "rftt"
 * ]
 * The correct order is: "wertf".
 *
 **********************************************************************/

class Solution {
public:
    /**
     * @param adj        Adjacent list
     * @param remains    Chars haven't been added to result
     * @param loop       Set of visited char
     * @param res        Result string
     * @param cur        Current char
     * @return True, if there's a loop in the graph.
     */
    bool topologicalSort(unordered_map<char, unordered_set<char>>& adj, unordered_set<char> loop,
                         unordered_set<char>& remains, string& res, char cur) {
        remains.erase(cur); // remove current char from <remains>.
        loop.insert(cur);   // add current char to <loop>.
        for (char next : adj[cur]) {
            if (loop.count(next)) return true; // if next char is already in the loop, return true.
            if (remains.count(next))
                if (topologicalSort(adj, loop, remains, res, next)) // DFS next char.
                    return true;
        }
        res = cur + res; // put current char in the front.
        return false;
    }
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_set<char> nodes;
        int n = words.size();
        // init all nodes
        for (string s : words) {
            for (char c : s) {
                if (!nodes.count(c)) {
                    nodes.insert(c);
                    adj[c] = unordered_set<char>();
                }
            }
        }
        // init adjacent list
        for (int i = 0; i < n-1; i++) {
            string a = words[i], b = words[i+1];
            int m = a.size(), n = b.size();
            bool found = 0;
            for (int k = 0; k < m && k < n; k++) {
                if (a[k] != b[k]) { // a[k]在b[k]前面
                    adj[a[k]].insert(b[k]);
                    break;
                }
            }
        }
        // topological sort
        string res;
        for (auto it : adj)
            if (nodes.count(it.first))
                if (topologicalSort(adj, unordered_set<char>(), nodes, res, it.first))
                    return "";
        // insert unused nodes
        for (char c : nodes)
            res += c;
        return res;
    }
};