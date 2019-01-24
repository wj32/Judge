class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        int leftSum = 0;
        int rightSum = accumulate(nums.begin() + 1, nums.end(), 0);

        if (leftSum == rightSum) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            leftSum += nums[i - 1];
            rightSum -= nums[i];
            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};
