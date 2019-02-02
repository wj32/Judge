class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        const int n = A.size();
        vector<vector<double>> r(n, vector<double>(K));
        r[0][0] = A[0];
        fill(r[0].begin() + 1, r[0].end(), numeric_limits<double>::min());
        for (int i = 1; i < n; i++) {
            double sum = A[i];
            for (int k = K - 1; k >= 1; k--) {
                r[i][k] = r[i - 1][k - 1] + sum;
            }
            for (int j = i - 1; j >= 1; j--) {
                sum += A[j];
                const auto average = sum / (i - j + 1);
                for (int k = K - 1; k >= 1; k--) {
                    r[i][k] = max(r[i][k], r[j - 1][k - 1] + average);
                }
            }
            sum += A[0];
            const auto average = sum / (i + 1);
            r[i][0] = average;
        }
        return r[n - 1][K - 1];
    }
};
