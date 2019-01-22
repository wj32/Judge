class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> p(N, vector<double>(N, 1));
        vector<vector<double>> q(N, vector<double>(N));
        while (K != 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    q[i][j] = 0;
                    for (const auto [di, dj] : {pair<int, int>{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                                                {1, 2}, {2, 1}, {2, -1}, {1, -2}}) {
                        const int ni = i + di;
                        const int nj = j + dj;
                        if ((ni >= 0) && (ni < N) && (nj >= 0) && (nj < N)) {
                            q[i][j] += p[ni][nj];
                        }
                    }
                    q[i][j] /= 8;
                }
            }
            swap(p, q);
            K--;
        }
        return p[r][c];
    }
};
