class Solution {
public:
    void search(const vector<vector<int>>& a, vector<vector<bool>>* b, int i, int j) {
        if ((*b)[i][j]) {
            return;
        }
        (*b)[i][j] = true;
        for (const auto& p : {pair<int, int>{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            const auto ni = i + p.first;
            const auto nj = j + p.second;
            if ((ni >= 0) && (ni < a.size()) && (nj >= 0) && (nj < a[0].size()) &&
                (a[ni][nj] >= a[i][j])) {
                search(a, b, ni, nj);
            }
        }
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return {};
        }
        const auto m = matrix.size();
        const auto n = matrix[0].size();

        vector<vector<bool>> tl(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            search(matrix, &tl, i, 0);
        }
        for (int j = 1; j < n; j++) {
            search(matrix, &tl, 0, j);
        }

        vector<vector<bool>> br(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            search(matrix, &br, i, n - 1);
        }
        for (int j = 0; j < n - 1; j++) {
            search(matrix, &br, m - 1, j);
        }

        vector<pair<int, int>> r;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (tl[i][j] && br[i][j]) {
                    r.push_back({i, j});
                }
            }
        }
        return r;
    }
};
