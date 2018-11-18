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
    ListNode* reverseList(ListNode* head) {
        ListNode* r = nullptr;
        while (head != nullptr) {
            const auto next = head->next;
            head->next = r;
            r = head;
            head = next;
        }
        return r;
    }
};
