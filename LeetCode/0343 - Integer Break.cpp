class Solution {
public:
    int powInt(int n, int k) {
        return static_cast<int>(pow(static_cast<double>(n), k) + 0.5);
    }

    int splitProduct(int n, int k) {
        const auto q = n / k;
        const auto r = n % k;
        return powInt(q, k - r) * powInt(q + 1, r);
    }

    int integerBreak(int n) {
        // Note that for a given number of parts, the product is maximized
        // when n is evenly distributed across the parts (AM-GM inequality).
        //
        // This is a discrete version of the following continuous problem:
        // maximize (n/k)^k with respect to k.
        // The derivative is (n/k)^k*(log(n/k)-1), which vanishes at k=n/e.
        //
        // To solve the discrete problem, just test the integer values
        // around n/e.

        const auto ideal = static_cast<int>(static_cast<double>(n) / exp(1));
        int maximum = 1;
        for (const int d : {-1, 0, 1}) {
            maximum = max(maximum, splitProduct(n, max(ideal + d, 2)));
        };
        return maximum;
    }
};
