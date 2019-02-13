class Solution {
public:
    int flood(vector<vector<int>>& grid, int i, int j, int component) {
        if (grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = component;

        int sum = 1;

        if (i > 0) {
            sum += flood(grid, i - 1, j, component);
        }
        if (i < grid.size() - 1) {
            sum += flood(grid, i + 1, j, component);
        }
        if (j > 0) {
            sum += flood(grid, i, j - 1, component);
        }
        if (j < grid[0].size() - 1) {
            sum += flood(grid, i, j + 1, component);
        }

        return sum;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        vector<int> componentSizes;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    const auto size = flood(grid, i, j, componentSizes.size() + 2);
                    componentSizes.push_back(size);
                    maxSize = max(maxSize, size);
                }
            }
        }

        unordered_set<int> components;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    if ((i > 0) && (grid[i - 1][j] >= 2)) {
                        components.insert(grid[i - 1][j]);
                    }
                    if ((i < grid.size() - 1) && (grid[i + 1][j] >= 2)) {
                        components.insert(grid[i + 1][j]);
                    }
                    if ((j > 0) && (grid[i][j - 1] >= 2)) {
                        components.insert(grid[i][j - 1]);
                    }
                    if ((j < grid[0].size() - 1) && (grid[i][j + 1] >= 2)) {
                        components.insert(grid[i][j + 1]);
                    }

                    int size = 1;
                    for (const auto component : components) {
                        size += componentSizes[component - 2];
                    }

                    maxSize = max(maxSize, size);
                    components.clear();
                }
            }
        }

        return maxSize;
    }
};
