class Solution {
public:
    struct Node {
        const string* word;
        unordered_map<char, Node*> children;
    };

    Node* makeTrie(const vector<string>& words) {
        const auto root = new Node{nullptr, {}};

        for (const auto& word : words) {
            auto node = root;

            for (const char c : word) {
                const auto it = node->children.find(c);
                if (it != node->children.end()) {
                    node = it->second;
                }
                else {
                    const auto newNode = new Node{nullptr, {}};
                    node->children.insert({c, newNode});
                    node = newNode;
                }
            }

            node->word = &word;
        }

        return root;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        const auto n = s.size();
        const auto trie = makeTrie(wordDict);
        vector<bool> r(n + 1);

        r[n] = true;

        for (int k = n - 1; k >= 0; k--) {
            auto node = trie;
            for (int j = k; j < n; j++) {
                const auto it = node->children.find(s[j]);
                if (it == node->children.end()) {
                    break;
                }
                node = it->second;
                if ((node->word != nullptr) && r[j + 1]) {
                    r[k] = true;
                    break;
                }
            }
        }

        return r[0];
    }
};
