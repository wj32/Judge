class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long result = 0;
        int prev = 0;
        const auto consecutiveSum = [&](const long first, const long count) {
            return count * (first * 2 + count - 1) / 2;
        };
        for (const auto x : nums) {
            if (const auto j = min(x - prev - 1, k); j > 0) {
                result += consecutiveSum(prev + 1, j);
                k -= j;
            }
            prev = x;
        }
        result += consecutiveSum(prev + 1, k);
        return result;
    }
};