// Sourse : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : Cecilia Chen
// Date   : 2015-11-10

/***********************************************************************
 *
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* cur = &head;
        while(l1 && l2) {
            if(l1->val < l2->val) { cur->next = l1; l1 = l1->next; } 
            else { cur->next = l2; l2 = l2->next; }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return head.next;
    }
};
