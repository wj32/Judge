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
    int length(ListNode* root) {
        int count = 0;
        while (root != nullptr) {
            count++;
            root = root->next;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        const int n = length(root);
        const int quotient = n / k;
        int remainder = n % k;
        vector<ListNode*> parts(k);

        for (int i = 0; i < k; i++) {
            int partLength = quotient;
            if (remainder != 0) {
                partLength++;
                remainder--;
            }

            auto tail = &root;
            for (int j = 0; j < partLength; j++) {
                tail = &(*tail)->next;
            }

            const auto next = *tail;
            *tail = nullptr;
            parts[i] = root;
            root = next;
        }

        return parts;
    }
};
