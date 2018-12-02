class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> r(n + 1);
        r[0] = vector<int>(n + 1, 0);
        r[1] = r[0];
        for (int count = 2; count <= n; count++) {
            r[count] = vector<int>(n - count + 2);
            for (int start = 1; start <= n - count + 1; start++) {
                const int end = start + count - 1;
                int minimum = numeric_limits<int>::max();
                for (int guess = start; guess < end; guess++) {
                    minimum = min(minimum, guess + max(r[guess - start][start], r[end - guess][guess + 1]));
                }
                r[count][start] = minimum;
            }
        }
        return r[n][1];
    }
};
