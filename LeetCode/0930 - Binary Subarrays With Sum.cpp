class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        for (int k = 0; k < nums.size(); ++k) {
            sum += nums[k];
            for (; i < k && sum > goal; ++i) {
                sum -= nums[i];
            }
            if (sum == goal) {
                for (j = max(j, i); j < k && nums[j] == 0; ++j) {
                }
                result += j - i + 1;
            }
        }
        return result;
    }
};