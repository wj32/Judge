class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int r = nums[0] + 1 == nums[1] ? 2 : 1;
        int s = r;
        for (size_t i = 2; i < nums.size(); ++i) {
            const auto d = nums[i] - nums[i - 1];
            if (abs(d) == 1 && d == nums[i - 2] - nums[i - 1]) {
                ++r;
            } else {
                r = nums[i - 1] + 1 == nums[i] ? 2 : 1;
            }
            s = max(s, r);
        }
        return s > 1 ? s : -1;
    }
};