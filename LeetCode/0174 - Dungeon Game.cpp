class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const auto m = dungeon.size();
        const auto n = dungeon[0].size();
        vector<vector<int>> r(m, vector<int>(n));

        r[m - 1][n - 1] = max(1 - dungeon[m - 1][n - 1], 1);

        for (int i = m - 2; i >= 0; i--) {
            r[i][n - 1] = max(r[i + 1][n - 1] - dungeon[i][n - 1], 1);
        }

        for (int j = n - 2; j >= 0; j--) {
            r[m - 1][j] = max(r[m - 1][j + 1] - dungeon[m - 1][j], 1);
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                r[i][j] = max(min(r[i + 1][j], r[i][j + 1]) - dungeon[i][j], 1);
            }
        }

        return r[0][0];
    }
};
