/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* moreHead = new ListNode(0);
        
        ListNode* less = lessHead;
        ListNode* more = moreHead;
        
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                more->next = head;
                more = more->next;
            }
            head = head->next;
        }
        
        more->next = nullptr;      // end the >= x list
        less->next = moreHead->next; // connect the two lists
        
        return lessHead->next;
    }
};
