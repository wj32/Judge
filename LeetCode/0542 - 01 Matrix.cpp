class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> r(m, vector<int>(n));
        vector<pair<int, int>> s;
        vector<pair<int, int>> t;
        int distance = 1;

        const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const auto examine = [&](int i, int j) {
            for (const auto& d : directions) {
                const int ni = i + d.first;
                const int nj = j + d.second;
                if ((ni >= 0) && (ni < m) && (nj >= 0) && (nj < n) &&
                    (matrix[ni][nj] == 1)) {
                    matrix[ni][nj] = -1;
                    t.push_back({ni, nj});
                }
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    r[i][j] = 0;
                    examine(i, j);
                }
            }
        }
        swap(s, t);

        while (!s.empty()) {
            for (const auto& p : s) {
                r[p.first][p.second] = distance;
                examine(p.first, p.second);
            }
            s.clear();
            swap(s, t);
            distance++;
        }

        return r;
    }
};
