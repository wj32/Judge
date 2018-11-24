class Solution {
public:
    int numSquares(int n) {
        vector<int> r(n + 1);
        r[0] = 0;
        for (int m = 1; m <= n; m++) {
            int minimum = m;
            int k = 1;
            while (true) {
                const int k2 = k * k;
                if (k2 > m) {
                    break;
                }
                minimum = min(minimum, r[m - k2]);
                k++;
            }
            r[m] = minimum + 1;
        }
        return r[n];
    }
};
