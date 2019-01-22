class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int maxRunLength = 1;
        int runLength = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                runLength++;
            }
            else {
                maxRunLength = max(maxRunLength, runLength);
                runLength = 1;
            }
        }
        maxRunLength = max(maxRunLength, runLength);
        return maxRunLength;
    }
};
