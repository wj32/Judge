class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const int OFFSET = 500;
        vector<vector<int>> r(nums.size(), vector<int>(OFFSET * 2 + 1, 1));
        int m = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                const auto k = nums[i] - nums[j] + OFFSET;
                r[i][k] = max(r[i][k], r[j][k] + 1);
                m = max(m, r[i][k]);
            }
        }
        return m;
    }
};