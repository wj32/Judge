class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        const auto m = grid.size();
        const auto n = grid[0].size();
        const auto flood = [&](int si, int sj) {
            queue<pair<int, int>> q;

            grid[si][sj] = 'v';
            q.push({si, sj});

            while (!q.empty()) {
                const auto p = q.front();
                q.pop();

                const auto examine = [&](int di, int dj) {
                    const int i = p.first + di;
                    const int j = p.second + dj;
                    if ((i >= 0) && (i < m) && (j >= 0) && (j < n) &&
                        (grid[i][j] == '1')) {
                        grid[i][j] = 'v';
                        q.push({i, j});
                    }
                };

                examine(-1, 0);
                examine(1, 0);
                examine(0, -1);
                examine(0, 1);
            }
        };

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    flood(i, j);
                }
            }
        }

        return count;
    }
};
