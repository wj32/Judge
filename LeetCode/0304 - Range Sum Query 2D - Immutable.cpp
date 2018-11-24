class NumMatrix {
private:
    vector<vector<int>> acc;

public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.size() == 0) {
            return;
        }
        const auto m = matrix.size();
        const auto n = matrix[0].size();
        acc = vector<vector<int>>(m + 1, vector<int>(n + 1));
        fill(acc[0].begin(), acc[0].end(), 0);
        for (size_t i = 1; i <= m; i++) {
            acc[i][0] = 0;
            int sum = 0;
            for (size_t j = 1; j <= n; j++) {
                sum += matrix[i - 1][j - 1];
                acc[i][j] = acc[i - 1][j] + sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return acc[row2 + 1][col2 + 1] + acc[row1][col1] - acc[row1][col2 + 1] - acc[row2 + 1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
