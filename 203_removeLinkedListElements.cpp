// Sourse : https://leetcode.com/problems/remove-linked-list-elements/
// Difficulty : Easy

/***********************************************************************
 *
 * Remove all elements from a linked list of integers that have value val.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode pre(0);
        pre.next = head;
        ListNode* node = &pre;
        while(node->next) {
            if (node->next->val == val) node->next = node->next->next;
            else node = node->next;
        }
        return pre.next;
    }
};