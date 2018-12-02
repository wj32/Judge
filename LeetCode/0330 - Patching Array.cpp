class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long upTo = 0;
        int index = 0;
        int patches = 0;
        while (upTo < n) {
            if ((index >= nums.size()) || (nums[index] > upTo + 1)) {
                patches++;
                upTo += upTo + 1;
            }
            else {
                upTo += nums[index];
                index++;
            }
        }
        return patches;
    }
};
