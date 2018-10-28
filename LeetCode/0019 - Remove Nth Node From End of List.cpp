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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode preHead(0);
        preHead.next = head;

        ListNode* current = &preHead;
        ListNode* forward = current;
        for (int i = 0; i < n; i++) {
            forward = forward->next;
        }

        while (forward->next != nullptr) {
            current = current->next;
            forward = forward->next;
        }

        current->next = current->next->next;

        return preHead.next;
    }
};
