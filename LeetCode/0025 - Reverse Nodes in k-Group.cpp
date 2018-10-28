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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode b(0);
        ListNode* tail = &b;

        while (head != nullptr) {
            ListNode* newTail = head;
            ListNode* newHead = head;

            head = head->next;

            int i = 1;
            for (; i < k; i++) {
                if (head == nullptr) {
                    break;
                }
                const auto next = head->next;
                head->next = newHead;
                newHead = head;
                head = next;
            }

            newTail->next = nullptr;

            if (i != k) {
                ListNode* revertTail = newHead;
                ListNode* revertHead = newHead;

                newHead = newHead->next;

                while (newHead != nullptr) {
                    const auto next = newHead->next;
                    newHead->next = revertHead;
                    revertHead = newHead;
                    newHead = next;
                }

                revertTail->next = nullptr;

                newHead = revertHead;
                newTail = revertTail;
            }

            tail->next = newHead;
            tail = newTail;
        }

        return b.next;
    }
};
