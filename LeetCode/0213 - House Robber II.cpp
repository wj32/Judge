class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        const auto robRange = [&](size_t start, size_t end) {
            int x = 0;
            int y = 0;
            for (size_t i = start; i < end; i++) {
                const int z = max(x + nums[i], y);
                x = y;
                y = z;
            }
            return y;
        };
        return max(robRange(0, nums.size() - 1), robRange(1, nums.size()));
    }
};
