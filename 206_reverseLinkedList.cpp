// Sourse : https://leetcode.com/problems/reverse-linked-list/
// Author : Cecilia Chen
// Date   : 2015-11-12

/***********************************************************************
 *
 * Reverse a singly linked list.
 * Hint: Do it both in iterative and recursive ways.
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
    
    ListNode* reverseIterative(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        while(head) {
            ListNode* next = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = next;
        }
        return dummy->next;
    }
    
    
    ListNode* reverseRecursive(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* cur = reverseRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return cur;
    }
};
