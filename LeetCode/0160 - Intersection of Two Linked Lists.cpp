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

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = length(headA);
        int lengthB = length(headB);
        if (lengthA < lengthB) {
            swap(headA, headB);
            swap(lengthA, lengthB);
        }

        const int lengthDiff = lengthA - lengthB;
        for (int i = 0; i < lengthDiff; i++) {
            headA = headA->next;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};
