class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = numeric_limits<int>::min();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        maxSum = max(maxSum, sum);
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};
