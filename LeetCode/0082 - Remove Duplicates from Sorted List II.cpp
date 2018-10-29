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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode b(0);
        ListNode* tail = &b;

        while (head != nullptr) {
            if ((head->next != nullptr) && (head->next->val == head->val)) {
                const auto val = head->val;

                do {
                    head = head->next;
                } while ((head != nullptr) && (head->val == val));
            }
            else {
                tail->next = head;
                tail = head;
                head = head->next;
            }
        }

        tail->next = nullptr;

        return b.next;
    }
};
