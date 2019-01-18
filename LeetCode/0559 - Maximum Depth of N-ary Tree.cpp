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
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int maximum = 0;
        for (const auto child : root->children) {
            maximum = max(maximum, maxDepth(child));
        }
        return maximum + 1;
    }
};
