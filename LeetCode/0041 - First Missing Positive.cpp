class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }

        bool nm = true;

        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] <= 0) || (nums[i] >= nums.size())) {
                if (nums[i] == nums.size()) {
                    nm = false;
                }
                nums[i] = 0;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % nums.size() != 0) {
                nums[nums[i] % nums.size()] += nums.size();
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] / nums.size() == 0) {
                return i;
            }
        }

        if (nm) {
            return nums.size();
        }

        return nums.size() + 1;
    }
};
