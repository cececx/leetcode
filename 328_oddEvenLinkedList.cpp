// Sourse : https://leetcode.com/problems/odd-even-linked-list/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes. 
 * Please note here we are talking about the node number and not the value in the nodes.
 * 
 * The program should run in O(1) space complexity and O(nodes) time complexity.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* oddEnd = head;
        ListNode* evenStart = head->next;
        ListNode* cur = head->next;
        //     1 ----- 2 ----- 3 ----- 4 ----- 5 ----- 6
        // (oddEnd) (evenStart)
        //           (cur)
        while(cur && cur->next) {
            oddEnd->next = cur->next;
            cur->next = cur->next->next;
            oddEnd->next->next = evenStart;
            cur = cur->next;
            oddEnd = oddEnd->next;
        }
        return head;
    }
};