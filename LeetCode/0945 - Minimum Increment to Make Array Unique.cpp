class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            const auto d = max(0, nums[i - 1] - nums[i] + 1);
            nums[i] += d;
            sum += d;
        }
        return sum;
    }
};