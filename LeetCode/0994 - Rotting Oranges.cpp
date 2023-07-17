class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount = 0;
        vector<pair<int, int>> rottenFrontierSet;
        vector<pair<int, int>> nextRottenFrontierSet;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ++freshCount;
                } else if (grid[i][j] == 2) {
                    rottenFrontierSet.emplace_back(i, j);
                }
            }
        }
        const auto process = [&](const auto i, const auto j) {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
                return;
            }
            grid[i][j] = 2;
            --freshCount;
            nextRottenFrontierSet.emplace_back(i, j);
        };
        int minutes = 0;
        while (!rottenFrontierSet.empty() && freshCount != 0) {
            for (const auto& [i, j] : rottenFrontierSet) {
                process(i - 1, j);
                process(i + 1, j);
                process(i, j - 1);
                process(i, j + 1);
            }
            rottenFrontierSet = nextRottenFrontierSet;
            nextRottenFrontierSet.clear();
            ++minutes;
        }
        return freshCount == 0 ? minutes : -1;
    }
};