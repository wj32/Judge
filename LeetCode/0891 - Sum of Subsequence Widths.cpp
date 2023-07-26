class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int prime = 1000000007;
        sort(nums.begin(), nums.end());
        long result = 0;
        long factor = 1;
        long subSum = 0;
        for (int i = 1; i < nums.size(); ++i, factor = (factor * 2) % prime) {
            // subSum = sum(j : [0, nums.size() - i); nums[j + i] - nums[j])
            //        = sum(j : [nums.size() - i, nums.size()); nums[j]) - sum(j : [0, i); nums[j])
            subSum += nums[nums.size() - i] - nums[i - 1];
            result = (result + ((factor * subSum) % prime)) % prime;
        }
        return static_cast<int>(result);
    }
};