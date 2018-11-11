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

    bool wordBreakTest(Node* trie, const string& s) {
        const auto n = s.size();
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

    void recurse(Node* trie, const string& s, vector<string>* r, string* v, int k) {
        if (k == s.size()) {
            r->push_back(*v);
            r->back().shrink_to_fit();
            return;
        }

        auto node = trie;

        while (k < s.size()) {
            const auto it = node->children.find(s[k]);
            if (it == node->children.end()) {
                break;
            }
            k++;
            node = it->second;
            if (node->word != nullptr) {
                const auto m = v->size();
                if (m != 0) {
                    v->append(1, ' ');
                }
                v->append(*node->word);
                recurse(trie, s, r, v, k);
                v->erase(m, v->size() - m);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        const auto trie = makeTrie(wordDict);
        if (!wordBreakTest(trie, s)) { // Just to avoid Time Limit Exceeded
            return {};
        }
        vector<string> r;
        string v;
        recurse(trie, s, &r, &v, 0);
        return r;
    }
};
