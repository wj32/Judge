class Solution {
public:
    struct Node {
        bool entry;
        int index;
        pair<int, int> position;
    };

    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) {
            return true;
        }

        const auto m = board.size();
        const auto n = board[0].size();
        stack<Node> s;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    s.push({true, 1, {i, j}});
                }
            }
        }

        while (!s.empty()) {
            auto* const u = &s.top();
            const auto p = u->position;

            if (u->entry) {
                if (u->index == word.size()) {
                    return true;
                }

                u->entry = false;
                board[p.first][p.second] = '\0';

                const auto tryPosition = [&](int di, int dj) {
                    const int i = p.first + di;
                    const int j = p.second + dj;
                    if ((i >= 0) && (i < m) && (j >= 0) && (j < n) &&
                        (board[i][j] == word[u->index])) {
                        s.push({true, u->index + 1, {i, j}});
                    }
                };

                tryPosition(-1, 0);
                tryPosition(1, 0);
                tryPosition(0, -1);
                tryPosition(0, 1);
            }
            else {
                board[p.first][p.second] = word[u->index - 1];
                s.pop();
            }
        }

        return false;
    }
};
