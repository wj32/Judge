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
    ListNode* swapPairs(ListNode* head) {
        ListNode b(0);
        ListNode* tail = &b;
        while (head != nullptr) {
            const auto next = head->next;
            if (next == nullptr) {
                tail->next = head;
                tail = head;
                break;
            }
            const auto nextNext = next->next;
            tail->next = next;
            next->next = head;
            tail = head;
            head = nextNext;
        }
        tail->next = nullptr;
        return b.next;
    }
};
