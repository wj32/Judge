class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = static_cast<int>(grid.size());
        if (m == 0) {
            return 1;
        }
        const int n = static_cast<int>(grid[0].size());
        if (n == 0) {
            return 1;
        }

        vector<vector<int>> r(m);
        for (int i = 0; i < m; i++) {
            r[i].resize(n);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = 0;
                if ((i != 0) || (j != 0)) {
                    const auto top = (i != 0) ? r[i - 1][j] : numeric_limits<int>::max();
                    const auto left = (j != 0) ? r[i][j - 1] : numeric_limits<int>::max();
                    x = min(top, left);
                }
                r[i][j] = grid[i][j] + x;
            }
        }

        return r[m - 1][n - 1];
    }
};
