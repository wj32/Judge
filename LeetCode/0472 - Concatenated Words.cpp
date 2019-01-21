class Solution {
public:
    struct Node {
        bool prefix;
        Node* parent;
        array<Node*, 26> children;
    };

    tuple<Node*, Node*, int> longestPrefix(Node* root, const string& word) {
        Node* prefixNode = root;
        int prefixLength = 0;
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            const char c = word[i];
            const auto child = &node->children[c - 'a'];
            if (*child == nullptr) {
                *child = new Node{false, node, {}};
            }
            node = *child;
            if (node->prefix) {
                prefixNode = node;
                prefixLength = i + 1;
            }
        }
        return {node, prefixNode, prefixLength};
    }

    bool composite(Node* root, const string& word, Node* prefixNode, int prefixLength) {
        if (prefixLength == word.size()) {
            return true;
        }
        assert(prefixNode->prefix);
        Node* wordNode = prefixNode;
        int wordIndex = prefixLength;
        Node* node = root;
        while (wordIndex < word.size()) {
            const char c = word[wordIndex];
            wordIndex++;
            wordNode = wordNode->children[c - 'a'];
            node = node->children[c - 'a'];
            if (node == nullptr) {
                break;
            }
            if (node->prefix && !wordNode->prefix) {
                wordNode->prefix = true;
                if (composite(root, word, wordNode, wordIndex)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        sort(words.begin(), words.end(), [&](const auto& a, const auto& b) {
            return a.size() < b.size();
        });
        vector<string> r;
        const auto root = new Node{false, nullptr, {}};
        for (const auto& word : words) {
            auto [endNode, prefixNode, prefixLength] = longestPrefix(root, word);
            while (prefixLength != 0) {
                if (prefixNode->prefix && composite(root, word, prefixNode, prefixLength)) {
                    r.push_back(word);
                    break;
                }
                prefixNode = prefixNode->parent;
                prefixLength--;
            }
            endNode->prefix = true;
        }
        return r;
    }
};
