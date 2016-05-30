// Sourse : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Difficulty : Easy

/***********************************************************************
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * 
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗            
 * B:     b1 → b2 → b3
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) { 
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pa;
    }
};