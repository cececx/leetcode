// Sourse : https://leetcode.com/problems/palindrome-linked-list/
// Difficulty : Easy

/***********************************************************************
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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

    // Time O(n), Space O(1)
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        int len = 1;
        ListNode* node = head;
        while (node = node->next) ++len;
        
        // reverse the first half
        ListNode prehead(0);
        prehead.next = head;
        node = head;
        for (int i=0; i<len/2 - 1; ++i) {
            ListNode* cur = node->next;
            node->next = cur->next;
            cur->next = prehead.next;
            prehead.next = cur;
        }
        if (len & 1) node = node->next->next; // odd
        else node = node->next; // even
        
        // check
        head = prehead.next;
        while (node) {
            if (head->val != node->val) return false;
            head = head->next;
            node = node->next;
        }
        return true;
    }
};