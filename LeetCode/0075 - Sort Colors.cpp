class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<int, 3> counts{};
        for (const auto x : nums) {
            ++counts[x];
        }
        fill(nums.begin(), nums.begin() + counts[0], 0);
        fill(nums.begin() + counts[0], nums.begin() + counts[0] + counts[1], 1);
        fill(nums.begin() + counts[0] + counts[1], nums.end(), 2);
    }
};