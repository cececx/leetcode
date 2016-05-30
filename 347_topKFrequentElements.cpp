// Sourse : https://leetcode.com/problems/top-k-frequent-elements/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 **********************************************************************/

class Solution {
public:
    /*
        1. Use hashmap to count frequency.
           Time O(n). Space O(n).
        
        2. Get k largest
           Sort:      O(nlogn)
           MaxHeap:   O(n + klogn)
           MinHeap:   O(k + (n-k)logk) √
    */
    
    struct comp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // get frequency
        unordered_map<int, int> map;
        for (int n : nums) ++map[n];
        
        // build min-heap of k-max
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        auto it = map.begin();
        for (int i=0; i<k; ++it, ++i) pq.push(*it);
        for (; it != map.end(); ++it) {
            if (pq.top().second < it->second) {
                pq.pop();
                pq.push(*it);
            }
        }
        
        // get result
        vector<int> res(k);
        for (int i = k-1; i >= 0; i--){
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};