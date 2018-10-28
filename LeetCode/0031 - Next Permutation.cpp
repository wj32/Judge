class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const size_t n = nums.size();
        for (size_t i = 1; i < n; i++) {
            // Invariant: nums[n - i .. n - 1] is sorted in ascending order.
            const auto pos = upper_bound(nums.begin() + n - i, nums.end(), nums[n - 1 - i]);
            if (pos != nums.end()) {
                swap(nums[n - 1 - i], *pos);
                break;
            } else {
                const auto x = nums[n - 1 - i];
                for (size_t j = 0; j < i; j++) {
                    nums[n - 1 - i + j] = nums[n - i + j];
                }
                nums[n - 1] = x;
            }
        }
    }
};
