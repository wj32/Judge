class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        const auto halfSize = nums.size() / 2;
        const auto translate = [&](const auto i) {
            return i < halfSize ? i * 2 : (i - halfSize) * 2 + 1;
        };
        int dst = 0;
        for (int src = 0; src < nums.size(); ++src) {
            if (nums[translate(src)] % 2 == 0) {
                swap(nums[translate(src)], nums[translate(dst)]);
                ++dst;
            }
        }
        return move(nums);
    }
};