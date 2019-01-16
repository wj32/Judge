class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int n = s.size();
        if (n <= 1) {
            return n;
        }
        vector<vector<int>> r(n + 1);
        for (int i = 0; i <= n; i++) {
            r[i] = vector<int>(n + 1 - i);
        }
        fill(r[0].begin(), r[0].end(), 0);
        fill(r[1].begin(), r[1].end(), 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                r[i][j] = (s[j] == s[j + i - 1]) ? (r[i - 2][j + 1] + 2) : max(r[i - 1][j], r[i - 1][j + 1]);
            }
        }
        return r[n][0];
    }
};
