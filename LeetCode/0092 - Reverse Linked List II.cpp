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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode a(0);
        ListNode* at = &a;
        ListNode r(0);
        ListNode* rt = &r;

        ListNode* node = head;
        for (int i = 1; i <= n; i++) {
            const auto next = node->next;

            if (i == m - 1) {
                a.next = head;
                at = node;
            }
            else if ((i >= m) && (i <= n)) {
                node->next = r.next;
                r.next = node;
                if (rt == &r) {
                    rt = node;
                }
            }

            node = next;
        }

        rt->next = node;
        at->next = r.next;

        return a.next;
    }
};
