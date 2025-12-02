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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap: stores pair (value, pointer to node)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // Push first node of each list
        for (auto node : lists) {
            if (node != nullptr) {
                pq.push({node->val, node});
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();

            // Add the smallest node to the result list
            tail->next = node;
            tail = tail->next;

            // Push the next node from the same list
            if (node->next != nullptr) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};
