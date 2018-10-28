class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= r) {
                r = i;
            }
        }

        return r == 0;
    }
};
