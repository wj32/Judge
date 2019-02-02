class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        struct Node {
            int count = 0;
            bool hasChildren = false;
            array<Node*, 26> children = {};
        };

        int totalCount = 0;
        Node root{};

        for (const auto& word : words) {
            auto node = &root;

            for (int i = word.size() - 1; i >= 0; i--) {
                if ((node != nullptr) && (node->count != 0)) {
                    totalCount -= node->count;
                    node->count = 0;
                }
                const auto child = &node->children[word[i] - 'a'];
                if (*child == nullptr) {
                    *child = new Node{};
                    node->hasChildren = true;
                }
                node = *child;
            }

            if ((node->count == 0) && !node->hasChildren) {
                node->count = word.size() + 1;
                totalCount += node->count;
            }
        }

        return totalCount;
    }
};
