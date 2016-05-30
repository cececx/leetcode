// Sourse : https://leetcode.com/problems/linked-list-cycle/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a linked list, determine if it has a cycle in it.
 * Require Space O(1)
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};