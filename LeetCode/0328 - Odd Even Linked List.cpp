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
    ListNode* oddEvenList(ListNode* head) {
        array<pair<ListNode*, ListNode*>, 2> lists = {};
        for (auto& p : lists) {
            p.first = new ListNode(0);
            p.second = p.first;
        }

        int index = 0;
        while (head != nullptr) {
            lists[index].second->next = head;
            lists[index].second = head;
            head = head->next;
            index = (index + 1) % lists.size();
        }

        lists[lists.size() - 1].second->next = nullptr;
        for (int i = lists.size() - 2; i >= 0; i--) {
            lists[i].second->next = lists[i + 1].first->next;
        }

        return lists[0].first->next;
    }
};
