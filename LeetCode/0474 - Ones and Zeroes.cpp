class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> r(m + 1, vector<int>(n + 1, 0));
        for (const auto str : strs) {
            int ones = 0;
            for (const char c : str) {
                if (c == '1') {
                    ones++;
                }
            }
            const int zeros = str.size() - ones;
            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    r[j][k] = max(r[j][k], r[j - zeros][k - ones] + 1);
                }
            }
        }
        return r[m][n];
    }
};
