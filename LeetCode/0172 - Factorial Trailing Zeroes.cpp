class Solution {
public:
    int trailingZeroes(int n) {
        long long x = n;
        long long p = 5;
        long long r = 0;

        while (p <= x) {
            r += x / p;
            p *= 5;
        }

        return static_cast<int>(r);
    }
};
