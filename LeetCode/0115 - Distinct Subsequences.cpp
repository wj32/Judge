class Solution {
public:
    int numDistinct(string s, string t) {
        const auto m = s.size();
        const auto n = t.size();
        vector<vector<int>> r(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            r[i][0] = 1;
        }
        for (int j = 1; j <= n; j++) {
            r[0][j] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                r[i][j] =
                    r[i - 1][j] +
                    ((s[i - 1] == t[j - 1]) ? r[i - 1][j - 1] : 0);
            }
        }

        return r[m][n];
    }
};
