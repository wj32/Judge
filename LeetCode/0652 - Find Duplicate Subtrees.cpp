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
    int recurse(TreeNode* node, map<tuple<int, int, int>, pair<int, bool>>& seenMap, vector<TreeNode*>& seenNodes) {
        if (node == nullptr) {
            return 0;
        }
        const auto leftId = recurse(node->left, seenMap, seenNodes);
        const auto rightId = recurse(node->right, seenMap, seenNodes);
        const auto key = make_tuple(leftId, node->val, rightId);
        const int newId = seenMap.size() + 1;
        const auto insertResult = seenMap.insert({key, {newId, false}});
        if (insertResult.second) {
            return newId;
        }
        else {
            if (!insertResult.first->second.second) {
                seenNodes.push_back(node);
                insertResult.first->second.second = true;
            }
            return insertResult.first->second.first;
        }
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<tuple<int, int, int>, pair<int, bool>> seenMap;
        vector<TreeNode*> seenNodes;
        recurse(root, seenMap, seenNodes);
        return seenNodes;
    }
};
