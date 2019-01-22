class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) {
            return 0;
        }

        int n = 1;
        for (const char c : s) {
            if (s[n - 1] != c) {
                s[n] = c;
                n++;
            }
        }
        s.resize(n);

        if (n <= 2) {
            return n;
        }

        vector<vector<int>> r(n + 1);
        for (int count = 0; count <= n; count++) {
            r[count] = vector<int>(n + 1 - count);
        }

        fill(r[0].begin(), r[0].end(), 0);
        fill(r[1].begin(), r[1].end(), 1);

        for (int count = 2; count <= n; count++) {
            for (int start = 0; start < n + 1 - count; start++) {
                int steps = r[count - 1][start + 1] + 1;
                for (int i = 2; i < count; i++) {
                    if (s[start + i] == s[start]) {
                        steps = min(steps, r[i][start] + r[count - i - 1][start + i + 1]);
                    }
                }
                r[count][start] = steps;
            }
        }

        return r[n][0];
    }
};
