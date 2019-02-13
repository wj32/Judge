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
    void gather(TreeNode* node, int remainingDistance, vector<int>& v) {
        if (node == nullptr) {
            return;
        }

        if (remainingDistance == 0) {
            v.push_back(node->val);
        }
        else if (remainingDistance > 0) {
            gather(node->left, remainingDistance - 1, v);
            gather(node->right, remainingDistance - 1, v);
        }
    }

    int find(TreeNode* node, TreeNode* target, int k, vector<int>& v) {
        if (node == nullptr) {
            return -1;
        }

        if (node == target) {
            gather(node, k, v);
            return 0;
        }
        else {
            int distance = find(node->left, target, k, v);
            if (distance != -1) {
                distance++;
                if (distance == k) {
                    v.push_back(node->val);
                }
                gather(node->right, k - distance - 1, v);
            }
            else {
                distance = find(node->right, target, k, v);
                if (distance != -1) {
                    distance++;
                    if (distance == k) {
                        v.push_back(node->val);
                    }
                    gather(node->left, k - distance - 1, v);
                }
            }
            return distance;
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> v;
        find(root, target, K, v);
        return v;
    }
};
