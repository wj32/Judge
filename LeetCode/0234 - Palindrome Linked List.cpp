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
    bool isPalindrome(ListNode* head) {
        const auto middle = [&] {
            auto slow = head;
            auto fast = head;
            while (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
                if (fast == nullptr) {
                    break;
                }
                fast = fast->next;
            }
            return slow;
        }();

        const auto reversed = [&] {
            ListNode* reversedHead = nullptr;
            auto node = middle;
            while (node != nullptr) {
                const auto next = node->next;
                node->next = reversedHead;
                reversedHead = node;
                node = next;
            }
            return reversedHead;
        }();

        auto node1 = head;
        auto node2 = reversed;
        while (node2 != nullptr) {
            if (node1->val != node2->val) {
                return false;
            }
            node1 = node1->next;
            node2 = node2->next;
        }

        return true;
    }
};
