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
    int recurse(TreeNode* node, int target, int sum, unordered_map<int, int>* sums) {
        if (node == nullptr) {
            return 0;
        }

        const int newSum = sum + node->val;
        const auto it = sums->find(newSum - target);
        int count = (it != sums->end()) ? it->second : 0;

        (*sums)[newSum]++;

        count += recurse(node->left, target, newSum, sums);
        count += recurse(node->right, target, newSum, sums);

        if (--(*sums)[newSum] == 0) {
            sums->erase(newSum);
        }

        return count;
    };

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> sums;
        sums[0] = 1;
        return recurse(root, sum, 0, &sums);
    }
};
