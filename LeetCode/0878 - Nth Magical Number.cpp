class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        --n;
        const int prime = 1000000007;
        const auto c = gcd(a, b);
        a /= c;
        b /= c;
        const int groupSize = a + b - 1;
        const auto base = a * b * long{n / groupSize};
        const auto remainder = n % groupSize;
        int x = a;
        int y = b;
        for (int i = 0; i < remainder; ++i) {
            if (x < y) {
                x += a;
            } else {
                y += b;
            }
        }
        return static_cast<int>((c * ((base + min(x, y)) % prime)) % prime);
    }
};