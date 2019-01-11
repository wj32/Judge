class Solution {
public:
    long long powLL(long long x, int k) {
        long long r = 1;
        while (k != 0) {
            if ((k % 2) == 0) {
                x *= x;
                k /= 2;
            }
            else {
                r *= x;
                k--;
            }
        }
        return r;
    }

    long long geometric(long long x, int k) {
        if (k == 0) {
            return 1;
        }
        else if (k == 1) {
            return 1 + x;
        }
        int j = max(min(k, static_cast<int>(63 * log(2) / log(x)) - 1), 1);
        long long p = powLL(x, j + 1);
        long long r = (p - 1) / (x - 1);
        if (j < k) {
            while (true) {
                j++;
                r += p;
                if (j == k) {
                    break;
                }
                p *= x;
            }
        }
        return r;
    }

    string smallestGoodBase(string n) {
        const long long x = stoll(n);
        const auto ks = max(static_cast<int>(ceil(log2(x))) - 1, 1);
        for (int k = ks; k >= 1; k--) {
            auto low = 2ll;
            auto high = static_cast<long long>(ceil(exp2(60.0 / k)));
            while (low <= high) {
                const auto mid = low + (high - low) / 2;
                const auto y = geometric(mid, k);
                if (y < x) {
                    low = mid + 1;
                }
                else if (y > x) {
                    high = mid - 1;
                }
                else {
                    return to_string(mid);
                }
            }
        }
        assert(false);
    }
};
