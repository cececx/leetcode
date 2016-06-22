// Source : https://leetcode.com/problems/partition-list/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a linked list and a value x, 
 * partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
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
 
 
// Two prehead. Time O(n), Space O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode head1(0), head2(0), *p1 = &head1, *p2 = &head2;
        while (head) {
            ListNode*& p = head->val < x ? p1 : p2;
            p = p->next = head;
            head = head->next;
        }
        p1->next = head2.next;
        p2->next = nullptr;
        return head1.next;
    }
};
