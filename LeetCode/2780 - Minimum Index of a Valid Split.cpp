class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const auto dominant = [&] {
            int dominant = nums[0];
            int count = 0;
            for (const auto x : nums) {
                if (count == 0) {
                    dominant = x;
                }
                count += x == dominant ? 1 : -1;
            }
            return dominant;
        }();
        const auto total = count(nums.begin(), nums.end(), dominant);
        int lhs = 0;
        for (int i = 0; i < nums.size(); ++i) {
            lhs += nums[i] == dominant;
            if (lhs * 2 > i + 1 && (total - lhs) * 2 > nums.size() - i - 1) {
                return i;
            }
        }
        return -1;
    }
};