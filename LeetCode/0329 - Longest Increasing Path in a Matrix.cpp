class Solution {
public:
    int search(const vector<vector<int>>& v, vector<vector<int>>* r, int i, int j) {
        if ((*r)[i][j] == -1) {
            int maximum = 0;
            for (const auto& p : {pair<int, int>{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                const int ni = i + p.first;
                const int nj = j + p.second;
                if ((ni >= 0) && (ni < v.size()) &&
                    (nj >= 0) && (nj < v[0].size()) &&
                    (v[ni][nj] > v[i][j])) {
                    maximum = max(maximum, search(v, r, ni, nj));
                }
            }
            (*r)[i][j] = maximum + 1;
        }
        return (*r)[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        const auto m = matrix.size();
        const auto n = matrix[0].size();
        vector<vector<int>> r(m, vector<int>(n, -1));
        int maximum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maximum = max(maximum, search(matrix, &r, i, j));
            }
        }
        return maximum;
    }
};
