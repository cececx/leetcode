// Sourse : https://leetcode.com/problems/longest-common-prefix/
// Author : Cecilia Chen
// Date   : 2015-11-03

/***********************************************************************
 *
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 * Given n will always be valid. Try to do this in one pass.
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

    // One pass 4ms O(n)

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * f = head, * r = head;
        for(int i=0; i<n+1; i++) {
            if(r == NULL){
                head = head->next;
                delete f;
                return head;
            }
            r = r->next;
        }
        while(r){ r = r->next; f = f->next; }
        r = f->next;
        f->next = f->next->next;
        delete r;
        return head;
    }
};