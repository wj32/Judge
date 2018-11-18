class WordDictionary {
private:
    struct Node {
        bool end;
        array<Node*, 26> children;
    };

    Node root = {false, {}};

    bool search(Node* node, const string& s, size_t i) {
        while (i < s.size()) {
            if (s[i] == '.') {
                for (const auto child : node->children) {
                    if (child != nullptr) {
                        if (search(child, s, i + 1)) {
                            return true;
                        }
                    }
                }
                return false;
            }
            else {
                const auto child = node->children[s[i] - 'a'];
                if (child == nullptr) {
                    return false;
                }
                node = child;
            }
            i++;
        }

        return node->end;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(&root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
