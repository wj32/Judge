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
    int recurse(TreeNode* node, unordered_map<int, int>& m, int& frequency, int& count) {
        if (node == nullptr) {
            return 0;
        }
        const int sum =
            node->val +
            recurse(node->left, m, frequency, count) +
            recurse(node->right, m, frequency, count);
        const int thisFrequency = ++m[sum];
        if (frequency < thisFrequency) {
            frequency = thisFrequency;
            count = 0;
        }
        if (frequency == thisFrequency) {
            count++;
        }
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        int frequency = 0;
        int count = 0;
        recurse(root, m, frequency, count);

        vector<int> r;
        r.reserve(count);
        for (const auto& p : m) {
            if (frequency == p.second) {
                r.push_back(p.first);
            }
        }
        return r;
    }
};
