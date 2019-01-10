class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> r = nums;
        for (int m = 2; m <= nums.size(); m++) {
            for (int i = 0; i <= nums.size() - m; i++) {
                r[i] = max(nums[i] - r[i + 1], nums[i + m - 1] - r[i]);
            }
        }
        return r[0] >= 0;
    }
};
