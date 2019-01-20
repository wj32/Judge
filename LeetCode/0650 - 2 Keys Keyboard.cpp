class Solution {
public:
    int minSteps(int n) {
        const int infinity = numeric_limits<int>::max() / 2;
        vector<vector<int>> r(max(n, 1) + 1);
        vector<int> m(max(n, 1) + 1);
        for (int i = 0; i <= n; i++) {
            r[i] = vector<int>((i / 2) + 1);
        }
        r[0][0] = infinity;
        m[0] = infinity;
        r[1][0] = 0;
        m[1] = 0;
        for (int i = 2; i <= n; i++) {
            int minimum = infinity;
            r[i][0] = infinity;
            int j = 1;
            for (; j * 3 <= i; j++) {
                r[i][j] = r[i - j][j] + 1;
                minimum = min(minimum, r[i][j]);
            }
            for (; j <= i / 2; j++) {
                r[i][j] = infinity;
            }
            if ((i % 2) == 0) {
                r[i][i / 2] = m[i / 2] + 2;
                minimum = min(minimum, r[i][i / 2]);
            }
            m[i] = minimum;
        }
        return m[n];
    }
};
