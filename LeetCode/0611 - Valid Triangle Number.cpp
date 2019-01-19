class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                const auto begin = nums.begin() + j + 1;
                count += lower_bound(begin, nums.end(), nums[i] + nums[j]) - begin;
            }
        }
        return count;
    }
};
