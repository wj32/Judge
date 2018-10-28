class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const auto m = static_cast<int>(matrix.size()) - 1;

        const auto innerRotate = [&](int i, int j) {
            const int x = matrix[i][j];
            matrix[i][j] = matrix[m - j][i];
            matrix[m - j][i] = matrix[m - i][m - j];
            matrix[m - i][m - j] = matrix[j][m - i];
            matrix[j][m - i] = x;
        };

        int row = 0;
        int left = 0;
        int right = m;

        while (left < right) {
            for (int col = left; col < right; col++) {
                innerRotate(row, col);
            }

            row++;
            left++;
            right--;
        }
    }
};
