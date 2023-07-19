class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long positive = 0;
        long negative = 0;
        int leastNegative = numeric_limits<int>::min();
        long result = numeric_limits<long>::min();
        for (const auto x : nums) {
            if (x > 0) {
                positive = max(positive, 1L) * x;
                negative *= x;
                result = max(result, positive);
            } else if (x < 0) {
                const auto oldPositive = positive;
                positive = negative * x;
                negative = max(oldPositive, 1L) * x;
                leastNegative = max(leastNegative, x);
                result = max(result, long{x});
                if (positive > 0) {
                    result = max(result, positive);
                }
            } else {
                result = max(result, 0L);
            }
        }
        if (positive > 0) {
            result = max(result, negative / leastNegative);
        }
        return result;
    }
};