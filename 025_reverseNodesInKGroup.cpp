// Sourse : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Cecilia Chen
// Date   : 2015-11-13

/***********************************************************************
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
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
    #define Recursive
    
    #ifdef Recursive
    
    /* recursive:
     *    C ---> B ---> A ---> D ---> E
     *    |             |      |
     *   head          end    cur
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode *cur = head, *end = head;
        for(int i=0; i<k; i++) {
            if(!cur) return head;
            cur = cur->next;
        }
        cur = head;
        for(int i=0; i<k-1; i++) {
            cur = end->next;
            end->next = cur->next;
            cur->next = head;
            head = cur;
        }
        end->next = reverseKGroup(end->next, k);
        return head;
    }
    
    #else
    
    /* iterative:
     *   (pre) ---> C ---> B ---> A ---> D ---> E
     *     |                      |      |
     *    head                   end    cur
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode prehead(0), *end = &prehead;
        prehead.next = head;
        head = end;
        int n = 0;
        while(end = end->next)
            ++n;
        while(n >= k) {
            end = head->next;
            for(int i=1; i<k; i++) {
                ListNode* cur = end->next;
                end->next = cur->next;
                cur->next = head->next;
                head->next = cur;
            }
            head = end;
            n -= k;
        }
        return prehead.next;
    }
    
    #endif
};
