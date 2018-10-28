class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = static_cast<int>(obstacleGrid.size());
        if (m == 0) {
            return 1;
        }
        const int n = static_cast<int>(obstacleGrid[0].size());
        if (n == 0) {
            return 1;
        }

        vector<vector<int>> r(m);
        for (int i = 0; i < m; i++) {
            r[i].resize(n);
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 0) {
                    const bool d = (i == m - 1);
                    const bool e = (j == n - 1);

                    if (d && e) {
                        r[i][j] = 1;
                    }
                    else {
                        r[i][j] = (d ? 0 : r[i + 1][j]) + (e ? 0 : r[i][j + 1]);
                    }
                }
                else {
                    r[i][j] = 0;
                }
            }
        }

        return r[0][0];
    }
};
