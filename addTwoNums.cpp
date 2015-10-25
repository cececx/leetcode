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

	// 36ms
	// use multiple while() instead of multiple if() in single while()
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

	// 44ms
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