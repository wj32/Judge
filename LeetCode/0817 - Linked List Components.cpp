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
    int numComponents(ListNode* head, vector<int>& G) {
        const int maximum = *max_element(G.begin(), G.end());
        vector<bool> presentMap(maximum + 1, false);
        for (const auto x : G) {
            presentMap[x] = true;
        }
        int components = 0;
        bool wasPresent = false;
        while (head != nullptr) {
            const bool present = (head->val <= maximum) && presentMap[head->val];
            if (wasPresent && !present) {
                components++;
            }
            wasPresent = present;
            head = head->next;
        }
        if (wasPresent) {
            components++;
        }
        return components;
    }
};
