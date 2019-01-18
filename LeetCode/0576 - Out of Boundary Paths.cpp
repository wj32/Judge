class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        const int prime = 1000000007;
        vector<vector<int>> r(m, vector<int>(n, 0));
        vector<vector<int>> s(m, vector<int>(n));
        for (int p = 0; p < N; p++) {
            for (int a = 0; a < m; a++) {
                for (int b = 0; b < n; b++) {
                    int sum = 0;
                    for (const auto& d : {pair<int, int>{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                        const int na = a + d.first;
                        const int nb = b + d.second;
                        if ((na >= 0) && (na < m) && (nb >= 0) && (nb < n)) {
                            sum = (sum + r[na][nb]) % prime;
                        }
                        else {
                            sum = (sum + 1) % prime;
                        }
                    }
                    s[a][b] = sum;
                }
            }
            swap(r, s);
        }
        return r[i][j];
    }
};
