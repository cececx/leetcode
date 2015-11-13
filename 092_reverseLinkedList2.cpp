// Sourse : https://leetcode.com/problems/reverse-linked-list-ii/
// Author : Cecilia Chen
// Date   : 2015-11-12

/***********************************************************************
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * 
 * For example: 
 * Given  1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        n -= m;
        ListNode prehead(0);
        prehead.next = head;
        ListNode* cur = &prehead;
        while (--m) cur = cur->next;
        ListNode* pre = cur;
        ListNode* end = cur->next;
        while (n--) {
            cur = end->next;
            end->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        return prehead.next;
    }
};
