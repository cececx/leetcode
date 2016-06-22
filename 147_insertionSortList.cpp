// Source : https://leetcode.com/problems/insertion-sort-list/
// Difficulty : Medium

/***********************************************************************
 *
 * Sort a linked list using insertion sort.
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
 
 
// ------------------------------------------------------------------
 
// 80ms. InsertSort. Time O(n2), Space O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode prehead(0), *cur = prehead.next = head;
        while (cur->next) {
            ListNode* pre = &prehead;
            while (pre->next->val < cur->next->val)
                pre = pre->next;
            if (pre != cur) {
                ListNode* node = cur->next;
                cur->next = node->next;
                node->next = pre->next;
                pre->next = node;
            }
            else cur = cur->next;
        }
        return prehead.next;
    }
};

// -----------------------------------------------------------------

// 24ms. std::sort. Time O(nlogn), Space O(n)
// I believe this is how people achieve 24ms. However this question requires inplace solution.
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // copy the data into an array
        vector<int> data;
        ListNode* cur = head;
        while (cur) {
            data.push_back(cur->val);
            cur = cur->next;
        }

        // sort the array
        sort(data.begin(), data.end());

        // then copy it back
        cur = head;
        for (int n : data) {
            cur->val = n;
            cur = cur->next;
        }
        return head;
    }
};


// Here is an O(nlogn) solution using mergesort that may also work for this question
// https://github.com/cecilia-cx/leetcode/blob/master/148_sortlist.cpp

