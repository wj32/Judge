class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int n = A.size();
        vector<vector<int>> r((2 * n) + 1, vector<int>((2 * n) + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] != 0) {
                    for (int k = 0; k < n; k++) {
                        for (int l = 0; l < n; l++) {
                            if (B[k][l] != 0) {
                                r[i - k + n][j - l + n]++;
                            }
                        }
                    }
                }
            }
        }
        int maximum = 0;
        for (int i = 0; i <= 2 * n; i++) {
            for (int j = 0; j <= 2 * n; j++) {
                maximum = max(maximum, r[i][j]);
            }
        }
        return maximum;
    }
};
