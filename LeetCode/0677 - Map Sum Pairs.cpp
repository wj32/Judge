class MapSum {
    struct Node {
        int val;
        int sum;
        Node* parent;
        array<Node*, 26> children;
    };

    Node root = {0, 0, nullptr, {}};

public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        Node* node = &root;
        for (const char c : key) {
            const auto child = &node->children[c - 'a'];
            if (*child == nullptr) {
                *child = new Node{0, 0, node, {}};
            }
            node = *child;
        }

        const int adjustment = val - node->val;
        node->val += adjustment;
        while (node != nullptr) {
            node->sum += adjustment;
            node = node->parent;
        }
    }

    int sum(string prefix) {
        Node* node = &root;
        for (const char c : prefix) {
            node = node->children[c - 'a'];
            if (node == nullptr) {
                return 0;
            }
        }
        return node->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
