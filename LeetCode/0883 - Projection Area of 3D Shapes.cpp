class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0;
        for (int i = 0; i < grid.size(); i++) {
            int maximum = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] != 0) {
                    area++;
                }
                maximum = max(maximum, grid[i][j]);
            }
            area += maximum;
        }
        for (int j = 0; j < grid.size(); j++) {
            int maximum = 0;
            for (int i = 0; i < grid.size(); i++) {
                maximum = max(maximum, grid[i][j]);
            }
            area += maximum;
        }
        return area;
    }
};
