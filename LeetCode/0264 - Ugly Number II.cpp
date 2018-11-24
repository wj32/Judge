class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> r(n);
        r[0] = 1;
        int j2 = 0;
        int j3 = 0;
        int j5 = 0;
        for (int i = 1; i < n; i++) {
            const int x2 = r[j2] * 2;
            const int x3 = r[j3] * 3;
            const int x5 = r[j5] * 5;
            const int x = min(min(x2, x3), x5);
            if (x2 == x) j2++;
            if (x3 == x) j3++;
            if (x5 == x) j5++;
            r[i] = x;
        }
        return r[n - 1];
    }
};
