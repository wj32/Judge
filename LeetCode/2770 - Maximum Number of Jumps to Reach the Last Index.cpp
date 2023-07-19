class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> r(nums.size());
        r[0] = 0;
        for (size_t i = 1; i < r.size(); ++i) {
            r[i] = -1;
            for (size_t j = 0; j < i; ++j) {
                if (r[j] != -1 && abs(nums[i] - nums[j]) <= target) {
                    r[i] = max(r[i], r[j] + 1);
                }
            }
        }
        return r.back();
    }
};