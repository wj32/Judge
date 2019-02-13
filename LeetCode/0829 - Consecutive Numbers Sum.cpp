class Solution {
public:
    int consecutiveNumbersSum(int N) {
        // If N is split into k parts, then 2N/k (the median of the sequence)
        // must be even (if k is odd) or 2N/k must be odd (if k is even).
        // Also, we must have N/k > k/2, which gives the bound k < sqrt(2n).

        int count = 0;
        const auto limit = static_cast<int>(ceil(sqrt(2 * N)));
        for (int k = 1; k < limit; k++) {
            if ((((2 * N) % k) == 0) && ((2 * N / k) % 2 == 1 - (k % 2))) {
                count++;
            }
        }
        return count;
    }
};
