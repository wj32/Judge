class Solution {
public:
    int minDistance(string word1, string word2) {
        const auto m = word1.size();
        const auto n = word2.size();
        vector<vector<int>> d(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            d[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            d[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(min(d[i - 1][j] + 1, d[i][j - 1] + 1),
                              d[i - 1][j - 1] +
                                ((word1[i - 1] == word2[j - 1]) ? 0 : 1));
            }
        }

        return d[m][n];
    }
};
