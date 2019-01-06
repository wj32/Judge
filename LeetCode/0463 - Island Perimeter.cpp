class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const auto m = grid.size();
        const auto n = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    perimeter +=
                        ((i == 0) || (grid[i - 1][j] == 0)) +
                        ((i == m - 1) || (grid[i + 1][j] == 0)) +
                        ((j == 0) || (grid[i][j - 1] == 0)) +
                        ((j == n - 1) || (grid[i][j + 1] == 0));
                }
            }
        }
        return perimeter;
    }
};
