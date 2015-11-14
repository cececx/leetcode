// Sourse : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Cecilia Chen
// Date   : 2015-11-13

/***********************************************************************
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
 
class Solution {
public:
    #define iterative
    
    #ifdef iterative
    
    // iterative solution
    ListNode* swapPairs(ListNode* head) {
        ListNode prehead(0), *pre = &prehead;
        prehead.next = head;
        while(pre->next && pre->next->next) {
            ListNode* cur = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = cur;
            pre = cur;
        }
        return prehead.next;
    }
    
    #else
    
    // recursive solution
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* tail = swapPairs(head->next->next);
        ListNode* cur = head->next;
        cur->next = head;
        head->next = tail;
        return cur;
    }
    
    #endif
};
