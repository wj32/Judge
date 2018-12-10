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
    int length(ListNode* node) {
        int count = 0;
        while (node != nullptr) {
            count++;
            node = node->next;
        }
        return count;
    }

    int recurse(ListNode* l1, ListNode* l2, int n2) {
        if (l1 == nullptr) {
            assert(l2 == nullptr);
            return 0;
        }
        const int sum = [&] {
            if (n2 == 0) {
                return l1->val + l2->val + recurse(l1->next, l2->next, 0);
            }
            else {
                return l1->val + recurse(l1->next, l2, n2 - 1);
            }
        }();
        const int carry = sum / 10;
        const int digit = sum % 10;
        l1->val = digit;
        return carry;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c1 = length(l1);
        int c2 = length(l2);
        if (c1 < c2) {
            swap(l1, l2);
            swap(c1, c2);
        }
        const int carry = recurse(l1, l2, c1 - c2);
        if (carry != 0) {
            const auto node = new ListNode(carry);
            node->next = l1;
            l1 = node;
        }
        return l1;
    }
};
