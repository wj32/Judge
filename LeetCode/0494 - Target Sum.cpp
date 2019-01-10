class Solution {
public:
    int recurse(const vector<int>& nums, const vector<int>& sums, int index, int target, vector<vector<int>>& cache) {
        if (index == nums.size()) {
            return (target == 0) ? 1 : 0;
        }

        if ((target < -sums[index]) || (target > sums[index])) {
            return 0;
        }
        if (((sums[index] + target) % 2) != 0) {
            return 0;
        }

        const auto cacheEntry = &cache[index][target + sums[index]];

        if (*cacheEntry == -1) {
            *cacheEntry = [&] {
                const int x = nums[index];

                if (x == 0) {
                    return 2 * recurse(nums, sums, index + 1, target, cache);
                }

                int endIndex = index + 1;

                while ((endIndex < nums.size()) && (nums[endIndex] == x)) {
                    endIndex++;
                }

                const int n = endIndex - index;
                int result = 0;
                int binom = 1;
                int sum = -x * n;

                for (int k = 0; k <= n; k++) {
                    result += binom * recurse(nums, sums, endIndex, target - sum, cache);
                    binom = binom * (n - k) / (k + 1);
                    sum += x * 2;
                }

                return result;
            }();
        }

        return *cacheEntry;
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        sort(nums.begin(), nums.end());

        vector<int> sums(nums.size());
        sums.back() = nums.back();
        for (int i = sums.size() - 2; i >= 0; i--) {
            sums[i] = nums[i] + sums[i + 1];
        }

        vector<vector<int>> cache(sums.size());
        for (int i = 0; i < sums.size(); i++) {
            cache[i] = vector<int>((sums[i] * 2) + 1, -1);
        }

        return recurse(nums, sums, 0, S, cache);
    }
};
