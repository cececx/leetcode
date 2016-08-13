// Sourse : https://leetcode.com/problems/reorder-list/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You must do this in-place without altering the nodes' values.
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
 

// Solution 1: One-Pass Recursive

// 嗯哼？这个应该一边递归一边移动right吧……
// 维持一个left一个right…… だって、单双数呢……
// 真烦，我们先BruteForce吧，O(n2)就O(n2)你咬我啊？
// 结果本宫还是写了个O(n)的递归一遍就跑过了嘻嘻嘻嘻嘻，万民跪拜吧
// 灵感来自于：不定义新变量，如何倒叙print链表
// 答案：void print(Node* node) { print(node->next); cout << node->val << endl; }

class Solution {
public: 
    // Time O(n), Space O(1)
    void reorderList(ListNode* head) {
        int length = 0;
        ListNode* node = head;
        while (node) {
            length++;
            node = node->next;
        }
        if (length < 3) return;
        reorder(head, node, length);
    }
    
    void reorder(ListNode* left, ListNode*& right, int remain) {
        if (remain == 1) { // 奇数的要跳过最后一个嘻嘻~
            right = left->next;
            left->next = nullptr;
            return;
        }
        if (remain == 2) { // 偶数的话要跳过两个呢~
            right = left->next->next;
            left->next->next = nullptr;
            return;
        }
        reorder(left->next, right, remain - 2); // 来吧递归~
        ListNode* node = right; // 然后把right挪到left后面就好辣
        right = right->next;
        node->next = left->next;
        left->next = node;
    }
};


// Solution 2:
// 链表分成两半，后半个先reverse一下，然后双指针插
// 这么浅显易懂的solution我竟然没有想到不过这个至少要遍历三次呢哼哼哼
// 还是觉得本宫赢了