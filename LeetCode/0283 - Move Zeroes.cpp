class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t dst = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[dst] = nums[i];
                if (i != dst) {
                    nums[i] = 0;
                }
                dst++;
            }
        }
    }
};
