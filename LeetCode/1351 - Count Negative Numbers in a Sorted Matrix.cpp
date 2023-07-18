class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        size_t count = 0;
        size_t j = grid[0].size();
        for (size_t i = 0; i < grid.size(); ++i) {
            while (j > 0 && grid[i][j - 1] < 0) {
                --j;
            }
            count += grid[0].size() - j;
        }
        return count;
    }
};