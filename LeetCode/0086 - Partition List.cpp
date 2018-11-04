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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = nullptr;
        ListNode* lessTail = nullptr;
        ListNode* greaterHead = nullptr;
        ListNode* greaterTail = nullptr;

        while (head != nullptr) {
            const auto next = head->next;
            const auto append = [&](ListNode** head, ListNode** tail, ListNode* node) {
                node->next = nullptr;
                if (*head != nullptr) {
                    (*tail)->next = node;
                    *tail = node;
                }
                else {
                    *head = node;
                    *tail = node;
                }
            };

            if (head->val < x) {
                append(&lessHead, &lessTail, head);
            }
            else {
                append(&greaterHead, &greaterTail, head);
            }

            head = next;
        }

        if (lessHead != nullptr) {
            lessTail->next = greaterHead;
            return lessHead;
        }
        else {
            return greaterHead;
        }
    }
};
