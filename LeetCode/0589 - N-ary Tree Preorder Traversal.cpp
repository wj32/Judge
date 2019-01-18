/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> r;
        stack<pair<Node*, int>> s;

        r.push_back(root->val);
        if (!root->children.empty()) {
            s.push({root, 0});
        }

        while (!s.empty()) {
            const auto node = s.top().first;
            auto& index = s.top().second;
            const auto child = node->children[index];

            index++;
            if (index == node->children.size()) {
                s.pop();
            }

            r.push_back(child->val);
            if (!child->children.empty()) {
                s.push({child, 0});
            }
        }

        return r;
    }
};
