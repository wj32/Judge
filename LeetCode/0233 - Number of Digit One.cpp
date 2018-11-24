class Solution {
public:
    long long count(long long n, long long p) {
        const auto left = n / p / 10;
        const auto digit = (n / p) % 10;
        const auto right = n % p;
        const auto partial = [&] {
            if (digit == 0) {
                return 0ll;
            }
            else if (digit == 1) {
                return right + 1;
            }
            else {
                return p;
            }
        }();
        return (left * p) + partial;
    }

    int countDigitOne(int n) {
        int r = 0;
        long long p = 1;
        while (p <= n) {
            r += static_cast<int>(count(n, p));
            p *= 10;
        }
        return r;
    }
};
