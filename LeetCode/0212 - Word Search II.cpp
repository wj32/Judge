class Solution {
public:
    struct Trie {
        const string* word;
        array<Trie*, 26> children;
    };

    struct Node {
        bool entry;
        char letter;
        Trie* trie;
        pair<int, int> position;
    };

    Trie* makeTrie(const vector<string>& words) {
        const auto root = new Trie{nullptr, {}};
        for (const auto& s : words) {
            auto node = root;
            for (const auto c : s) {
                const auto child = &node->children[c - 'a'];
                if (*child == nullptr) {
                    *child = new Trie{nullptr, {}};
                }
                node = *child;
            }
            node->word = &s;
        }
        return root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const auto trieRoot = makeTrie(words);
        vector<string> r;

        const auto m = board.size();
        const auto n = board[0].size();

        stack<Node> s;

        const auto search = [&](Trie* st, int si, int sj) {
            s.push({true, '\0', st, {si, sj}});

            while (!s.empty()) {
                auto* const u = &s.top();
                const auto p = u->position;

                if (u->entry) {
                    u->entry = false;

                    if (u->trie->word != nullptr) {
                        r.push_back(*u->trie->word);
                        u->trie->word = nullptr;
                    }

                    u->letter = board[p.first][p.second];
                    board[p.first][p.second] = '\0';

                    const auto tryPosition = [&](int di, int dj) {
                        const int i = p.first + di;
                        const int j = p.second + dj;
                        if ((i >= 0) && (i < m) && (j >= 0) && (j < n) &&
                            (board[i][j] != '\0')) {
                            const auto child = u->trie->children[board[i][j] - 'a'];
                            if (child != nullptr) {

                                s.push({true, '\0', child, {i, j}});
                            }
                        }
                    };

                    tryPosition(-1, 0);
                    tryPosition(1, 0);
                    tryPosition(0, -1);
                    tryPosition(0, 1);
                }
                else {
                    board[p.first][p.second] = u->letter;
                    s.pop();
                }
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                const auto child = trieRoot->children[board[i][j] - 'a'];
                if (child != nullptr) {
                    search(child, i, j);
                }
            }
        }

        return r;
    }
};
