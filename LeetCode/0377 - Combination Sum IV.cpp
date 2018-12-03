class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const auto n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        vector<int> r(target + 1);
        r[0] = 1;
        for (int i = 1; i <= target; i++) {
            int sum = 0;
            for (const int num : nums) {
                if (num > i) {
                    break;
                }
                sum += r[i - num];
            }
            r[i] = sum;
        }
        return r[target];
    }
};
