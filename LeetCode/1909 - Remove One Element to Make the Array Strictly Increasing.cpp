class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int violations = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] >= nums[i]) {
                ++violations;
                if (i == 1) {
                    nums[i - 1] = 0;
                } else if (i >= 2 && nums[i - 2] < nums[i]) {
                    nums[i - 1] = nums[i - 2];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return violations <= 1;
    }
};