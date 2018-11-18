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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode b(0);
        b.next = head;
        ListNode* node = &b;

        while (node->next != nullptr) {
            if (node->next->val == val) {
                node->next = node->next->next;
            }
            else {
                node = node->next;
            }
        }

        return b.next;
    }
};
