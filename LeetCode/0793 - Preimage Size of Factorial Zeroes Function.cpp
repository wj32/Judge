long long trailingZeroes(long long n) {
    long long x = n;
    long long p = 5;
    long long r = 0;

    while (p <= x) {
        r += x / p;
        p *= 5;
    }

    return r;
}

class Solution {
public:
    template<typename Func>
    long long lowerBound(long long low, long long high, long long target, Func f) {
        while (low < high) {
            const auto mid = low + (high - low) / 2;
            const auto x = f(mid);
            if (x < target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }

    template<typename Func>
    long long upperBound(long long low, long long high, long long target, Func f) {
        while (low < high) {
            const auto mid = low + (high - low) / 2;
            const auto x = f(mid);
            if (x <= target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }

    int preimageSizeFZF(int K) {
        const auto limit = 1ll << 60;
        return static_cast<int>(upperBound(0, limit, K, trailingZeroes) - lowerBound(0, limit, K, trailingZeroes));
    }
};
