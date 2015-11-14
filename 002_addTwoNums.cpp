// Sourse : https://leetcode.com/problems/add-two-numbers/
// Author : Cecilia Chen
// Date   : 2015-10-23

/***********************************************************************
 *
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
	#define SOLUTION_1
	
	#ifdef SOLUTION_1
	
	// 44ms concise solution
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0), *p = &head;
		int extra = 0;
		while (l1 || l2 || extra) {
			if (l1) extra += l1->val, l1 = l1->next;
			if (l2) extra += l2->val, l2 = l2->next;
			p->next = new ListNode(extra % 10);
			extra /= 10;
			p = p->next;
		}
		return head.next;
	}
	
	#else
	
	// 36ms using multiple while statements instead of using if statement inside while loop, 
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0), *p = &head;
		int extra = 0;
		while (l1 && l2) {
			extra += l1->val + l2->val;
			p->next = new ListNode(extra % 10);
			extra /= 10; p = p->next; l1 = l1->next; l2 = l2->next;
		}
		while (l1) {
			extra += l1->val;
			p->next = new ListNode(extra % 10);
			extra /= 10; p = p->next; l1 = l1->next;
		}
		while (l2) {
			extra += l2->val;
			p->next = new ListNode(extra % 10);
			extra /= 10; p = p->next; l2 = l2->next;
		}
		if (extra) p->next = new ListNode(1);
		return head.next;
	}

	#endif
	
};
