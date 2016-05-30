// Sourse : https://leetcode.com/problems/lru-cache/
// Difficulty: Hard

/***********************************************************************
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache. 
 * It should support the following operations: get and set.
 * 
 * get(key)
 *  - Get the value (will always be positive) of the key if the key exists in the cache, 
 *    otherwise return -1.
 * 
 * set(key, value)
 *  - Set or insert the value if the key is not already present. 
 *    When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 *
 **********************************************************************/

 
// 72ms, Time O(1), Space O(n)
// Implemented doubly linked-list
 
class LRUCache{
private:
    struct ListNode {                       // node structure of doubly linked list
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };
    ListNode* head = new ListNode(-1, 0);   // list head
    ListNode* tail = new ListNode(-1, 0);   // list tail
    int size = 0;                           // size of the list    

    // remove node from the list
    ListNode* removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        -- size;
        return node;
    }
    // insert node after the head node
    ListNode* insertNode(ListNode* node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
        ++ size;
        return node;
    }
    // update the recent-used node
    ListNode* updateNode(ListNode* node) {
        removeNode(node);
        insertNode(node);
        return node;
    }
    // get node by its key from the map
    ListNode* getNode(int key) {
        auto it = map.find(key);
        return it == map.end() ? nullptr : it->second;
    }
    
    
    
private:    
    int capacity = 0;                       // capacity
    unordered_map<int, ListNode*> map;      // hashmap to store <key, node> 
    
public:
    LRUCache(int capacity) : capacity(capacity) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        ListNode* node = getNode(key);
        return node ? updateNode(node)->val : -1;
    }
    
    void set(int key, int value) {
        ListNode* node = getNode(key);
        if (node) { // update node
            updateNode(node)->val = value;
            return;
        }
        if (size == capacity) { // delete last node 
           ListNode* dnode = removeNode(tail->prev);
           map.erase(dnode->key);
           delete dnode;
        }
        map[key] = insertNode(new ListNode(key, value)); // insert new node
    }
};




// -------------------------------------------------------------------

// 172ms, Time(??), Space(??)
// Used std::list

class LRUCache{
private:
    int capacity = 0;
    list<pair<int, int>> cache; // doubly-linked-list
    unordered_map<int, list<pair<int,int>>::iterator> map; // hashmap to store <key, node> 
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void set(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {           // update node if exists
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
            return;
        }
        if (cache.size() == capacity) {  // erase last node, if list is full
            map.erase(cache.back().first);
            cache.pop_back();
        }
        cache.emplace_front(key, value); // add new
        map[key] = cache.begin();
    }
};