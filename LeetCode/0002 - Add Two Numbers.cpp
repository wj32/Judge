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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l3start = nullptr;
        ListNode* l3 = nullptr;

        while ((l1 != nullptr) || (l2 != nullptr) || (carry != 0)) {
            const int sum =
                ((l1 != nullptr) ? l1->val : 0) +
                ((l2 != nullptr) ? l2->val : 0) +
                carry;
            const int rem = sum % 10;
            carry = sum / 10;

            ListNode* l3new = new ListNode(rem);

            if (l3start == nullptr) {
                l3start = l3new;
            } else {
                l3->next = l3new;
            }

            l3 = l3new;

            if (l1 != nullptr) {
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return l3start;
    }
};