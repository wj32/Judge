class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int y = 0;
        for (const auto x : nums) {
            y ^= x;
        }
        return y;
    }
};
