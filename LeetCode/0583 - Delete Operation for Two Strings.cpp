class Solution {
public:
    int minDistance(string word1, string word2) {
        const auto m = word1.size();
        const auto n = word2.size();
        vector<vector<int>> r(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            r[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            r[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                r[i][j] = (word1[i - 1] == word2[j - 1]) ? r[i - 1][j - 1]
                                                         : (min(r[i - 1][j], r[i][j - 1]) + 1);
            }
        }
        return r[m][n];
    }
};
