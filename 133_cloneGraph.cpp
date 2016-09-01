// Sourse : https://leetcode.com/problems/clone-graph/
// Difficulty : Medium

/***********************************************************************
 *
 * Clone an undirected graph. 
 * Each node in the graph contains a label and a list of its neighbors.
 *
 **********************************************************************/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
// Notes: 憋听它瞎说label是唯一标识，判断标准是原node的reference
// 尝试BFS来避免stackoverflow
// 反正我就写了个recursive DFS ヽ(●´ω｀●)

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        return cloneNode(node, map);
    }
    UndirectedGraphNode *cloneNode(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& map) {
        if (map.count(node)) return map[node];
        UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
        map[node] = clone;
        for (auto n : node->neighbors)
            clone->neighbors.push_back(cloneNode(n, map));
        return clone;
    }
};