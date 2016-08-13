// Sourse : https://leetcode.com/problems/copy-list-with-random-pointer/
// Difficulty : Hard

/***********************************************************************
 *
 * A linked list is given such that each node contains an additional random pointer 
 * which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 **********************************************************************/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 
// Solution 1
// Typical recursive deep copy
// Time O(n), Space O(n) 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> map;
        return copyNode(head, map);
    }
    
    RandomListNode *copyNode(RandomListNode *node, unordered_map<RandomListNode*, RandomListNode*>& map) {
        if (!node) return nullptr;
        if (map.find(node) != map.end())
            return map[node];
        RandomListNode* copy = new RandomListNode(node->label);
        map[node] = copy;
        copy->next = copyNode(node->next, map);
        copy->random = copyNode(node->random, map);
        return copy;
    }
};