class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        bool first = true;
        int closest;

        for (int i = 0; i < nums.size(); i++) {
            const int t = target - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                const int sum = nums[i] + nums[j] + nums[k];
                if (first || (abs(closest - target) > abs(sum - target))) {
                    closest = sum;
                    first = false;
                }
                if (nums[j] + nums[k] < t) {
                    j++;
                } else if (nums[j] + nums[k] > t) {
                    k--;
                } else {
                    return sum;
                }
            }
        }

        return closest;
    }
};
