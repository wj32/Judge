class Solution {
public:
    int numTilings(int N) {
        const int prime = 1000000007;
        long long x1 = 1;
        long long x2 = 0;
        long long y1 = 0;
        while (N != 0) {
            const auto x0 = (x1 + x2 + (2 * y1)) % prime;
            const auto y0 = (y1 + x2) % prime;
            x2 = x1;
            x1 = x0;
            y1 = y0;
            N--;
        }
        return static_cast<int>(x1);
    }
};
