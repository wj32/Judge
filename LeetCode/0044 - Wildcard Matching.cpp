class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = p.size();
        const int n = s.size();
        vector<vector<bool>> a(m + 1);
        for (auto& v : a) {
            v.resize(n + 1, false);
        }

        a[m][n] = true;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                switch (p[i]) {
                    case '*':
                        a[i][j] = ((j < n) ? a[i][j + 1] : false) || a[i + 1][j];
                        break;
                    case '?':
                        a[i][j] = (j < n) ? a[i + 1][j + 1] : false;
                        break;
                    default:
                        a[i][j] = (j < n) ? ((p[i] == s[j]) && a[i + 1][j + 1]) : false;
                }
            }
        }

        /*
        cout << " ";
        for (int j = 0; j < n; j++) {
            cout << s[j];
        }
        cout << "|" << endl;

        for (int i = 0; i <= m; i++) {
            cout << ((i < m) ? p[i] : '|');

            for (int j = 0; j <= n; j++) {
                cout << a[i][j] ? 'x' : ' ';
            }

            cout << endl;
        }
        */

        return a[0][0];
    }
};
