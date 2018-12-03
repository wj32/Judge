class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const auto m = matrix.size();
        const auto n = matrix[0].size();

        int maximum = numeric_limits<int>::min();

        if (m <= n) {
            vector<vector<int>> v(m + 1, vector<int>(n));
            fill(v[0].begin(), v[0].end(), 0);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    v[i + 1][j] = v[i][j] + matrix[i][j];
                }
            }
            for (int i0 = 0; i0 < m; i0++) {
                for (int i1 = i0 + 1; i1 <= m; i1++) {
                    set<int> s;
                    int sum = 0;
                    s.insert(sum);
                    for (int j = 0; j < n; j++) {
                        sum += v[i1][j] - v[i0][j];
                        const auto it = s.lower_bound(sum - k);
                        if (it != s.end()) {
                            maximum = max(maximum, sum - *it);
                        }
                        s.insert(sum);
                    }
                }
            }
        }
        else {
            vector<vector<int>> h(n + 1, vector<int>(m));
            fill(h[0].begin(), h[0].end(), 0);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    h[j + 1][i] = h[j][i] + matrix[i][j];
                }
            }
            for (int j0 = 0; j0 < n; j0++) {
                for (int j1 = j0 + 1; j1 <= n; j1++) {
                    set<int> s;
                    int sum = 0;
                    s.insert(sum);
                    for (int i = 0; i < m; i++) {
                        sum += h[j1][i] - h[j0][i];
                        const auto it = s.lower_bound(sum - k);
                        if (it != s.end()) {
                            maximum = max(maximum, sum - *it);
                        }
                        s.insert(sum);
                    }
                }
            }
        }

        return maximum;
    }
};
