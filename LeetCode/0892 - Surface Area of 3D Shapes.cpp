class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                const auto h = grid[i][j];
                if (h != 0) {
                    area += 2;
                    for (const auto [di, dj] : {pair<int, int>{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                        const auto ni = i + di;
                        const auto nj = j + dj;
                        int nh = 0;
                        if ((ni >= 0) && (ni < grid.size()) && (nj >= 0) && (nj < grid.size())) {
                            nh = grid[ni][nj];
                        }
                        area += max(h - nh, 0);
                    }
                }
            }
        }
        return area;
    }
};
