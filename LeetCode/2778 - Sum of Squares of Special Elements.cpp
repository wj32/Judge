class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums.size() % (i + 1) == 0) {
                r += nums[i] * nums[i];
            }
        }
        return r;
    }
};