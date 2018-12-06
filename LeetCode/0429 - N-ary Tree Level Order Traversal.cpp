/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> r;
        vector<int> s;

        vector<Node*> p;
        vector<Node*> q;

        if (root != nullptr) {
            p.push_back(root);
        }

        while (!p.empty()) {
            for (const auto node : p) {
                s.push_back(node->val);
                q.insert(q.end(), node->children.begin(), node->children.end());
            }
            r.push_back(move(s));
            s.clear();
            swap(p, q);
            q.clear();
        }

        return r;
    }
};
