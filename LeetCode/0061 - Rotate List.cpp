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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* forward = head;
        int i = 0;
        while (i < k) {
            forward = forward->next;
            i++;

            if (forward == nullptr) {
                k %= i;
                forward = head;
                i = 0;
            }
        }

        if (k == 0) {
            return head;
        }

        ListNode* last = nullptr;
        ListNode* newHead = head;
        ListNode* previous = nullptr;
        while (forward != nullptr) {
            last = forward;
            previous = newHead;
            forward = forward->next;
            newHead = newHead->next;
        }

        last->next = head;
        previous->next = nullptr;

        return newHead;
    }
};
