class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) {
            return 0;
        }

        struct Entry {
            int height;
            int i;
            int j;
        };
        const auto cmp = [&](const Entry& a, const Entry& b) {
            return a.height > b.height;
        };
        priority_queue<Entry, vector<Entry>, decltype(cmp)> q(cmp);

        const int m = heightMap.size();
        const int n = heightMap[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for (const auto [i, j] : {pair<int, int>{0, 0}, {m - 1, 0}, {0, n - 1}, {m - 1, n - 1}}) {
            seen[i][j] = true;
        }
        for (int i = 1; i < m - 1; i++) {
            for (const int j : {0, n - 1}) {
                seen[i][j] = true;
                q.push({heightMap[i][j], i, j});
            }
        }
        for (int j = 1; j < n - 1; j++) {
            for (const int i : {0, m - 1}) {
                seen[i][j] = true;
                q.push({heightMap[i][j], i, j});
            }
        }

        int volume = 0;

        while (!q.empty()) {
            const auto [h, i, j] = q.top();
            q.pop();

            for (const auto [di, dj] : {pair<int, int>{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                const int ni = i + di;
                const int nj = j + dj;
                if ((ni >= 0) && (ni < m) && (nj >= 0) && (nj < n) && !seen[ni][nj]) {
                    const int nh = heightMap[ni][nj];
                    const int dh = max(h - nh, 0);
                    seen[ni][nj] = true;
                    q.push({nh + dh, ni, nj});
                    volume += dh;
                }
            }
        }

        return volume;
    }
};
