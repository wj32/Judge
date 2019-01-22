class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool violated = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (violated) {
                    return false;
                }
                if ((i - 1 > 0) && (nums[i] < nums[i - 2])) {
                    nums[i] = nums[i - 1];
                }
                else {
                    nums[i - 1] = nums[i];
                }
                violated = true;
            }
        }
        return true;
    }
};
