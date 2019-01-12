class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int end = 0;
        int maximum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < maximum) {
                end = i + 1;
            }
            else {
                maximum = nums[i];
            }
        }

        int start = nums.size();
        int minimum = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > minimum) {
                start = i;
            }
            else {
                minimum = nums[i];
            }
        }

        return max(end - start, 0);
    }
};
