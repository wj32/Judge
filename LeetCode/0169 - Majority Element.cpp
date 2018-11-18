class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxCount = 1;
        int maxCountElement = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                count = 0;
            }
            count++;

            if (maxCount < count) {
                maxCount = count;
                maxCountElement = nums[i];
            }
        }

        return maxCountElement;
    }
};
