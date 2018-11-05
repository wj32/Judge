/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* node) {
        int n = 0;
        while (node != nullptr) {
            n++;
            node = node->next;
        }
        return n;
    }

    struct Entry {
        int low;
        int high;
        int mid;
        TreeNode* node;
    };

    TreeNode* sortedListToBST(ListNode* head) {
        const int n = length(head);
        if (n == 0) {
            return nullptr;
        }

        stack<Entry> s;
        int index = 0;

        const auto root = new TreeNode(0);
        s.push({0, n - 1, (n - 1) / 2, root});

        while (head != nullptr) {
            while (index != s.top().mid) {
                const auto low = s.top().low;
                const auto high = s.top().high;
                const auto mid = s.top().mid;
                assert(index >= low);
                if (index > high) {
                    s.pop();
                }
                else {
                    const auto node = new TreeNode(0);
                    if (index < mid) {
                        s.top().node->left = node;
                        s.push({low, mid - 1, (low + mid - 1) / 2, node});
                    }
                    else {
                        s.top().node->right = node;
                        s.push({mid + 1, high, (mid + 1 + high) / 2, node});
                    }
                }
            }

            s.top().node->val = head->val;
            head = head->next;
            index++;
        }

        return root;
    }
};
