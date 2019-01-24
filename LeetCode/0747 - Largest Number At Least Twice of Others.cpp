class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        const auto it = max_element(nums.begin(), nums.end());
        const auto m = *it / 2;
        *it = -1;
        return all_of(nums.begin(), nums.end(), [&](int x) { return x <= m; }) ? (it - nums.begin()) : -1;
    }
};
