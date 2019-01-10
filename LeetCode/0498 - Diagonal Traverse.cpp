class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> r;
        r.reserve(m * n);
        for (int k = 0; k <= m + n - 2; k++) {
            const int start = max(0, k - n + 1);
            const int end = min(m - 1, k);
            if ((k % 2) == 0) {
                for (int i = end; i >= start; i--) {
                    r.push_back(matrix[i][k - i]);
                }
            }
            else {
                for (int i = start; i <= end; i++) {
                    r.push_back(matrix[i][k - i]);
                }
            }
        }
        return r;
    }
};
