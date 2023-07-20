class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        for (int i = nums.size() - 1; i > 0; --i) {
            nums[i] -= nums[i - 1];
        }
        for (int i = 0; i < nums.size() - k; ++i) {
            if (nums[i] < 0) {
                return false;
            }
            nums[i + k] += nums[i];
        }
        return all_of(nums.end() - k + 1, nums.end(), [](const auto c) { return c == 0; });
    }
};