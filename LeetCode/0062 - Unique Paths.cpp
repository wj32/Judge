class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) {
            return uniquePaths(n, m);
        }

        // (m + n - 2) choose (m - 1)

        long k = 1;
        for (int i = n; i <= m + n - 2; i++) {
            k *= i;
        }

        long j = 1;
        for (int i = 1; i <= m - 1; i++) {
            j *= i;
        }

        return static_cast<int>(k / j);
    }
};
