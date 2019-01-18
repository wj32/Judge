class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            int length = 0;
            while (nums[j] != -1) {
                length++;
                const int k = nums[j];
                nums[j] = -1;
                j = k;
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
