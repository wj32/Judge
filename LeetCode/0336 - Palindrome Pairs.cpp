class Solution {
public:
    struct Trie {
        vector<int> matches;
        vector<int> ends;
        array<Trie*, 26> children;
    };

    bool isPalindrome(const string& s, int start, int count) {
        for (int i = 0; i < count / 2; i++) {
            if (s[start + i] != s[start + count - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie root{{}, {}, {}};

        for (int i = 0; i < words.size(); i++) {
            const auto& word = words[i];
            auto node = &root;
            int k = word.size();
            for (int j = word.size(); j >= 0; j--) {
                if (isPalindrome(word, 0, j)) {
                    while (k > j) {
                        k--;
                        const auto child = &node->children[word[k] - 'a'];
                        if (*child == nullptr) {
                            *child = new Trie{{}, {}, {}};
                        }
                        node = *child;
                    }
                    node->matches.push_back(i);
                    if (j == 0) {
                        node->ends.push_back(i);
                    }
                }
            }
        }

        vector<vector<int>> r;

        for (int i = 0; i < words.size(); i++) {
            const auto& word = words[i];
            auto node = &root;
            for (int j = 0; j < word.size(); j++) {
                if (!node->ends.empty() && isPalindrome(word, j, word.size() - j)) {
                    for (const auto end : node->ends) {
                        if (end != i) {
                            r.push_back({i, end});
                        }
                    }
                }
                node = node->children[word[j] - 'a'];
                if (node == nullptr) {
                    break;
                }
            }
            if (node != nullptr) {
                for (const auto match : node->matches) {
                    if (match != i) {
                        r.push_back({i, match});
                    }
                }
            }
        }

        return r;
    }
};
