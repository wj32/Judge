class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int r = nums[0];
        for (const auto x : nums) {
            if (pair(abs(x), -x) < pair(abs(r), -r)) {
                r = x;
            }
        }
        return r;
    }
};