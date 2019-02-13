class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        const int m = A.size();
        const int n = A[0].size();
        if (m == n) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(A[i][j], A[j][i]);
                }
            }
            return A;
        }
        else {
            vector<vector<int>> B(n, vector<int>(m));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    B[j][i] = A[i][j];
                }
            }
            return B;
        }
    }
};
