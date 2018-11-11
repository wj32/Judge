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
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }

        const auto middle = [&] {
            ListNode* slowPrev = nullptr;
            auto slow = head;
            auto fast = head;

            while (fast != nullptr) {
                slowPrev = slow;
                slow = slow->next;
                fast = fast->next;
                if (fast == nullptr) {
                    break;
                }
                fast = fast->next;
            }

            slowPrev->next = nullptr;

            return slow;
        }();

        const auto reversedHead = [&] {
            ListNode* reversedHead = nullptr;
            auto next = middle;

            while (next != nullptr) {
                const auto current = next;
                next = next->next;
                current->next = reversedHead;
                reversedHead = current;
            }

            return reversedHead;
        }();

        array<ListNode*, 2> lists = {head, reversedHead};
        int listIndex = 0;

        ListNode base(0);
        auto tail = &base;

        while (lists[listIndex] != nullptr) {
            const auto current = lists[listIndex];
            tail->next = current;
            tail = current;
            lists[listIndex] = current->next;
            listIndex = (listIndex + 1) % lists.size();
        }

        tail->next = nullptr;
    }
};
