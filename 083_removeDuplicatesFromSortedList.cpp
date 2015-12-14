// Sourse : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
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
	// 16ms
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* pre = head;
        ListNode* cur;
        while(pre->next) {
            cur = pre->next;
            if(pre->val == cur->val) { 
                pre->next = cur->next; 
                delete cur; 
            }
            else pre = cur;
        }
        return head;
    }
};