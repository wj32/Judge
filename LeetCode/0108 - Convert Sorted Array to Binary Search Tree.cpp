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
    TreeNode* recurse(const vector<int>& a, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        const int mid = low + (high - low) / 2;
        const auto t = new TreeNode(a[mid]);
        t->left = recurse(a, low, mid - 1);
        t->right = recurse(a, mid + 1, high);
        return t;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurse(nums, 0, nums.size() - 1);
    }
};
