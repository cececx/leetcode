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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// solution1(l1, l2);
		solution2(l1, l2);
	}

	// instead of using if statement inside while loop, using multiple while statements.
	// optimized runtime 44ms -> 36ms.
	// not sure if this is a proper way.
	ListNode* solution2(ListNode* l1, ListNode* l2) {
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

	// 44ms concise solution
	ListNode* solution1(ListNode* l1, ListNode* l2) {
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
};