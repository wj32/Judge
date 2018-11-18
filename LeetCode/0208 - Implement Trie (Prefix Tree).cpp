class Trie {
private:
    struct Node {
        bool end;
        array<Node*, 26> children;
    };

    Node root = {false, {}};

public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = &root;
        for (const auto c : word) {
            const auto child = &node->children[c - 'a'];
            if (*child == nullptr) {
                *child = new Node{false, {}};
            }
            node = *child;
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = &root;
        for (const auto c : word) {
            const auto child = &node->children[c - 'a'];
            if (*child == nullptr) {
                return false;
            }
            node = *child;
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = &root;
        for (const auto c : prefix) {
            const auto child = &node->children[c - 'a'];
            if (*child == nullptr) {
                return false;
            }
            node = *child;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
