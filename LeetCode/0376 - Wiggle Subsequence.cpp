class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int count = 1;
        int sign = 0;
        for (int i = 1; i < nums.size(); i++) {
            const int newSign = nums[i] - nums[i - 1];
            if (((sign >= 0) && (newSign < 0)) ||
                ((sign <= 0) && (newSign > 0))) {
                count++;
                sign = newSign;
            }
        }
        return count;
    }
};
