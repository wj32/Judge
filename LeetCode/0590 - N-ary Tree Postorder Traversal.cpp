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
    vector<int> postorder(Node* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> r;
        stack<pair<Node*, int>> s;

        s.push({root, 0});

        while (!s.empty()) {
            const auto node = s.top().first;
            auto& index = s.top().second;

            if (index == node->children.size()) {
                r.push_back(node->val);
                s.pop();
                continue;
            }

            const auto child = node->children[index];
            index++;
            s.push({child, 0});
        }

        return r;
    }
};
