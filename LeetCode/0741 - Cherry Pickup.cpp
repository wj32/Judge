class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int p = (2 * n) - 1;
        vector<vector<int>> r(n, vector<int>(n));
        vector<vector<int>> s(n, vector<int>(n));

        r[0][0] = grid[0][0];

        for (int i = 1; i < p; i++) {
            const int low = max(0, i - (n - 1));
            const int high = min(i, n - 1);

            for (int j = low; j <= high; j++) {
                const int x = grid[i - j][j];

                for (int k = low; k <= high; k++) {
                    const int y = grid[i - k][k];

                    if ((x == -1) || (y == -1)) {
                        s[j][k] = numeric_limits<int>::min();
                    }
                    else {
                        int a = numeric_limits<int>::min();
                        if (j >= 1) {
                            if (k >= 1) {
                                a = max(a, r[j - 1][k - 1]);
                            }
                            if (i - k >= 1) {
                                a = max(a, r[j - 1][k]);
                            }
                        }
                        if (i - j >= 1) {
                            if (k >= 1) {
                                a = max(a, r[j][k - 1]);
                            }
                            if (i - k >= 1) {
                                a = max(a, r[j][k]);
                            }
                        }

                        s[j][k] = a + ((j == k) ? x : (x + y));
                    }
                }
            }

            swap(r, s);
        }

        return max(r[n - 1][n - 1], 0);
    }
};
