class Solution {
public:
    bool recurse(vector<int>& nums, int target, int index, vector<int>& sums, int lastChoice) {
        if (index == nums.size()) {
            return true;
        }
        int start = 0;
        if ((index > 0) && (nums[index] == nums[index - 1])) {
            start = lastChoice; // Break symmetry for duplicate matchstick lengths
        }
        for (int i = start; i < sums.size(); i++) {
            if (sums[i] + nums[index] <= target) {
                sums[i] += nums[index];
                const bool result = recurse(nums, target, index + 1, sums, i);
                sums[i] -= nums[index];
                if (result) {
                    return true;
                }
            }
            if (sums[i] == 0) {
                break; // Break symmetry between sides
            }
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) {
            return false;
        }
        sort(nums.begin(), nums.end(), [&](int x, int y) { return y < x; });
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum % 4) != 0) {
            return false;
        }
        const int target = sum / 4;
        if (nums.front() > target) {
            return false;
        }
        if (nums.back() == target) {
            return true;
        }
        vector<int> sums(4, 0);
        return recurse(nums, target, 0, sums, -1);
    }
};
