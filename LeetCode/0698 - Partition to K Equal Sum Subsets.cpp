class Solution {
public:
    bool recurse(vector<int>& nums, int target, int index, vector<int>& sums, int lastChoice) {
        if (index == nums.size()) {
            return true;
        }
        int start = 0;
        if ((index > 0) && (nums[index] == nums[index - 1])) {
            start = lastChoice; // Break symmetry for duplicate numbers
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
                break; // Break symmetry between sets
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return false;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) { return b < a; });
        const auto sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum % k) != 0) {
            return false;
        }
        const auto target = sum / k;
        if (nums.front() > target) {
            return false;
        }
        if (nums.back() == target) {
            return true;
        }

        vector<int> sums(k, 0);
        return recurse(nums, target, 0, sums, -1);
    }
};
