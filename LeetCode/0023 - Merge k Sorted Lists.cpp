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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using node_t = pair<int, ListNode*>;

        ListNode b(0);
        ListNode* tail = &b;
        priority_queue<node_t, vector<node_t>, std::greater<node_t>> pq;

        for (auto list : lists) {
            if (list != nullptr) {
                pq.push({list->val, list});
            }
        }

        while (!pq.empty()) {
            const auto p = pq.top();
            pq.pop();

            tail->next = p.second;
            tail = p.second;

            if (tail->next != nullptr) {
                pq.push({tail->next->val, tail->next});
            }
        }

        return b.next;
    }
};
