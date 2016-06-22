// Source : https://leetcode.com/problems/linked-list-cycle-ii/
// Difficulty: Medium

/***********************************************************************
 *
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Note: Do not modify the linked list.
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
 
 
/*
    不循环的长度是A，循环的长度是B，从循环起点到相遇地点走了K，
    slow走了：A + K
    fast走了：A + K + x * B    (x > 0)
    fast - slow = slow
    A + K = x * B
            
    >>  K = x * B - A
        
    所以slow再走A次就到起点啦，这个时候head也走了A次到起点啦
*/
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr;
        while (head != slow) {
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};
