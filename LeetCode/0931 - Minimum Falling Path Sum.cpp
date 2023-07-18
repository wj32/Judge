class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (size_t i = 1; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                auto m = matrix[i - 1][j];
                if (j > 0) {
                    m = min(m, matrix[i - 1][j - 1]);
                }
                if (j + 1 < matrix[0].size()) {
                    m = min(m, matrix[i - 1][j + 1]);
                }
                matrix[i][j] += m;
            }
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};