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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        const auto h = [&] {
            int h = -1;
            auto node = root;
            do {
                h++;
                node = node->left;
            } while (node != nullptr);
            return h;
        }();

        const auto present = [&](int index) {
            auto node = root;
            for (int i = h - 1; i >= 0; i--) {
                if ((index & (1 << i)) == 0) {
                    node = node->left;
                }
                else {
                    node = node->right;
                }
            }
            return node != nullptr;
        };

        int low = 0;
        int high = (1 << h) - 1;

        while (low < high) {
            const int mid = low + (high - low + 1) / 2;
            if (present(mid)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }

        assert(low == high);

        return (1 << h) + low;
    }
};
