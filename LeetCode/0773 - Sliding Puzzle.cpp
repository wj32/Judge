class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        union Board {
            struct {
                char m[2][3];
                char zi;
                char zj;
            } b;
            long asLong;
        };

        const Board target{{{{1, 2, 3}, {4, 5, 0}}, 1, 2}};
        const auto start = [&] {
            Board b{};
            int zi = -1;
            int zj = -1;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    b.b.m[i][j] = static_cast<char>(board[i][j]);
                    if (board[i][j] == 0) {
                        zi = i;
                        zj = j;
                    }
                }
            }
            b.b.zi = static_cast<char>(zi);
            b.b.zj = static_cast<char>(zj);
            return b;
        }();

        if (start.asLong == target.asLong) {
            return 0;
        }

        struct Entry {
            int distance;
            Board board;
        };
        const auto cmp = [&](const Entry& a, const Entry& b) {
            return a.distance > b.distance;
        };
        priority_queue<Entry, vector<Entry>, decltype(cmp)> q(cmp);
        unordered_set<long> seen;

        q.push({0, start});

        while (!q.empty()) {
            const auto entry = q.top();
            q.pop();

            if (entry.board.asLong == target.asLong) {
                return entry.distance;
            }

            if (seen.insert(entry.board.asLong).second) {
                const auto enqueue = [&](int si, int sj) {
                    Board b = entry.board;
                    swap(b.b.m[b.b.zi][b.b.zj], b.b.m[si][sj]);
                    b.b.zi = static_cast<char>(si);
                    b.b.zj = static_cast<char>(sj);
                    if (seen.find(b.asLong) == seen.end()) {
                        q.push({entry.distance + 1, b});
                    }
                };

                if (entry.board.b.zi > 0) {
                    enqueue(entry.board.b.zi - 1, entry.board.b.zj);
                }
                if (entry.board.b.zi < 1) {
                    enqueue(entry.board.b.zi + 1, entry.board.b.zj);
                }
                if (entry.board.b.zj > 0) {
                    enqueue(entry.board.b.zi, entry.board.b.zj - 1);
                }
                if (entry.board.b.zj < 2) {
                    enqueue(entry.board.b.zi, entry.board.b.zj + 1);
                }
            }
        }

        return -1;
    }
};
