class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        const auto m = matrix.size();
        const auto n = matrix[0].size();
        vector<vector<int>> s(m, vector<int>(n));
        vector<int> up(n, 0);
        int maxSide = 0;

        for (int i = 0; i < m; i++) {
            int left = 0;

            for (int j = 0; j < n; j++) {
                const auto b = (matrix[i][j] == '1');
                left = b ? (left + 1) : 0;
                up[j] = b ? (up[j] + 1) : 0;

                if (b && (i != 0) && (j != 0)) {
                    s[i][j] = min(s[i - 1][j - 1] + 1, min(left, up[j]));
                }
                else {
                    s[i][j] = b ? 1 : 0;
                }

                maxSide = max(maxSide, s[i][j]);
            }
        }

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << s[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return maxSide * maxSide;
    }
};
