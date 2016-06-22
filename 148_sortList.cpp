// Source : https://leetcode.com/problems/sort-list/
// Difficulty: Medium

/***********************************************************************
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 **********************************************************************/
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 
// Mergesort. Time O(nlogn), Space O(1)

class Solution {
private:
    // 把从node开始的n个节点撕下来嘿嘿，返回被撕掉的新head
    ListNode* divide(ListNode* node, int n) {
        while (--n && node) 
            node = node->next;
        if (!node) 
            return nullptr;
        ListNode* next = node->next;
        node->next = nullptr;
        return next;
    }
    
    // merge到prehead后面，返回merge之后list的最后一个节点
    ListNode* merge(ListNode* p, ListNode* l, ListNode* r) {
        while (l && r) {
            ListNode*& t = l->val < r->val ? l : r;
            p->next = t;
            p = p->next;
            t = t->next;
        }
        p->next = l ? l : r;
        while (p->next) p = p->next;
        return p;
    }
    
public:
    // 嘻嘻来吧我们来mergesort OvO
    ListNode* sortList(ListNode* head) {
        
        // count length
        int len = 0;
        ListNode* node = head;
        while (node) {
            len ++;
            node = node->next;
        }
        
        // ヽ(●´ω｀●)
        ListNode prehead(0);
        prehead.next = head;
        for (int step = 1; step < len; step <<= 1) {
            ListNode* prev = &prehead;
            ListNode* left = prev->next;
            while (left) {
                ListNode* right = divide(left, step);
                ListNode* next = divide(right, step);
                prev = merge(prev, left, right);
                left = next;
            }
        }
        return prehead.next;
    }
};