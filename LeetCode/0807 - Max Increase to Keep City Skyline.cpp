class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<int> rowMax(m, numeric_limits<int>::min());
        vector<int> colMax(n, numeric_limits<int>::min());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }

        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return sum;
    }
};
