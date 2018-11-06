class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        const auto m = board.size();
        const auto n = board[0].size();
        vector<pair<int, int>> s;

        const auto floodFill = [&](pair<int, int> start) {
            if (board[start.first][start.second] != 'O') {
                return;
            }

            s.clear();
            s.push_back(start);

            while (!s.empty()) {
                const auto p = s.back();
                s.pop_back();

                if (board[p.first][p.second] != 'O') {
                    continue;
                }
                board[p.first][p.second] = 'V';

                const auto examine = [&](int di, int dj) {
                    const auto i = p.first + di;
                    const auto j = p.second + dj;
                    if ((i >= 0) && (i < m) &&
                        (j >= 0) && (j < n) &&
                        (board[i][j] == 'O')) {
                        s.push_back({i, j});
                    }
                };

                examine(-1, 0);
                examine(1, 0);
                examine(0, -1);
                examine(0, 1);
            }
        };

        for (int i = 0; i < m; i++) {
            floodFill({i, 0});
            floodFill({i, n - 1});
        }

        for (int j = 1; j < n - 1; j++) {
            floodFill({0, j});
            floodFill({m - 1, j});
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
