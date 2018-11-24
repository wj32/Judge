class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        return ((nums.size() * (nums.size() + 1)) / 2) - sum;
    }
};
