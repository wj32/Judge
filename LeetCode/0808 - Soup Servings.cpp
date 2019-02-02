class Solution {
public:
    double soupServings(int N) {
        N = (N + 25 - 1) / 25;
        if (N > 500) {
            return 1.0;
        }

        vector<vector<double>> r(N + 1, vector<double>(N + 1));
        r[0][0] = 0.5;
        fill(r[0].begin() + 1, r[0].end(), 1.0);
        for (int i = 1; i <= N; i++) {
            r[i][0] = 0.0;
        }

        for (int d = 1; d <= 2 * N; d++) {
            for (int i = max(d - N, 1); i <= min(d - 1, N); i++) {
                const int j = d - i;
                r[i][j] = 0.25 * (r[max(i - 4, 0)][j] +
                                  r[max(i - 3, 0)][max(j - 1, 0)] +
                                  r[max(i - 2, 0)][max(j - 2, 0)] +
                                  r[max(i - 1, 0)][max(j - 3, 0)]);
            }
        }

        return r[N][N];
    }
};
