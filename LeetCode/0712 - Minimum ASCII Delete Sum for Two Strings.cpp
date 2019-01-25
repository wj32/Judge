class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const auto n1 = s1.size();
        const auto n2 = s2.size();
        vector<vector<int>> r(n1 + 1, vector<int>(n2 + 1));

        r[0][0] = 0;
        for (int i1 = 1; i1 <= n1; i1++) {
            r[i1][0] = r[i1 - 1][0] + s1[i1 - 1];
        }
        for (int i2 = 1; i2 <= n2; i2++) {
            r[0][i2] = r[0][i2 - 1] + s2[i2 - 1];
        }

        for (int i1 = 1; i1 <= n1; i1++) {
            for (int i2 = 1; i2 <= n2; i2++) {
                if (s1[i1 - 1] == s2[i2 - 1]) {
                    r[i1][i2] = r[i1 - 1][i2 - 1];
                }
                else {
                    r[i1][i2] = min(r[i1 - 1][i2] + s1[i1 - 1],
                                    r[i1][i2 - 1] + s2[i2 - 1]);
                }
            }
        }

        return r[n1][n2];
    }
};
