class Solution {
public:
    bool checkValidString(string s) {
        const int n = s.size();
        vector<vector<bool>> r(n + 1, vector<bool>((n / 2) + 1));
        fill(r[0].begin(), r[0].end(), false);
        r[0][0] = true;
        for (int i = 1; i <= n; i++) {
            switch (s[i - 1]) {
                case '(':
                    r[i][0] = false;
                    for (int j = 1; j <= n / 2; j++) {
                        r[i][j] = r[i - 1][j - 1];
                    }
                    break;
                case ')':
                    for (int j = 0; j < n / 2; j++) {
                        r[i][j] = r[i - 1][j + 1];
                    }
                    r[i][n / 2] = false;
                    break;
                case '*':
                    for (int j = 0; j <= n / 2; j++) {
                        r[i][j] = r[i - 1][j] ||
                                  ((j >= 1) ? r[i - 1][j - 1] : false) ||
                                  ((j < n / 2) ? r[i - 1][j + 1] : false);
                    }
                    break;
            }
        }
        return r[n][0];
    }
};
