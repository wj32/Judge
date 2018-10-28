class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }

        const auto m = matrix.size();
        const auto n = matrix[0].size();
        bool top = false;
        bool left = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        top = true;
                    }
                    else {
                        matrix[0][j] = 0;
                    }

                    if (j == 0) {
                        left = true;
                    }
                    else {
                        matrix[i][0] = 0;
                    }
                }
            }
        }

        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (left) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (top) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};
