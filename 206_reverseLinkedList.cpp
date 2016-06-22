// Source : https://leetcode.com/problems/reverse-linked-list/
// Difficulty: Easy

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

 
// Iterative
ListNode* reverse(ListNode* head) {
    ListNode last = NULL;
    while (head) {
        ListNode* next = head->next;
        head->next = last;
        last = head;
        head = next;
     }
    return last;
}

// Recursive
ListNode* reverse(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* cur = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return cur;
}
