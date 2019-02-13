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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        while ((fast != nullptr) && (fast->next != nullptr)) {
            fast = fast->next->next;
            head = head->next;
        }
        return head;
    }
};
