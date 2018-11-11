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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while ((l1 != nullptr) && (l2 != nullptr)) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }

        if (l1 == nullptr) {
            tail->next = l2;
        } else {
            tail->next = l1;
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        array<ListNode*, sizeof(int) * 8> lists = {};
        int limit = 0;

        while (head != nullptr) {
            const auto current = head;
            head = head->next;
            current->next = nullptr;

            bool occupied = (lists[0] != nullptr);
            lists[0] = mergeTwoLists(lists[0], current);
            int index = 1;
            for (; occupied; index++) {
                occupied = (lists[index] != nullptr);
                lists[index] = mergeTwoLists(lists[index], lists[index - 1]);
                lists[index - 1] = nullptr;
            }
            limit = max(limit, index);
        }

        for (int index = 1; index < limit; index++) {
            lists[index] = mergeTwoLists(lists[index], lists[index - 1]);
        }

        if (limit != 0) {
            return lists[limit - 1];
        }
        else {
            return nullptr;
        }
    }
};
