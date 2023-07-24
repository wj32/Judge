class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIndex = -1;
        int maxIndex = -1;
        int i = 0;
        long result = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] < minK || nums[j] > maxK) {
                i = j + 1;
                minIndex = -1;
                maxIndex = -1;
                continue;
            }
            if (nums[j] == minK) {
                minIndex = j;
            }
            if (nums[j] == maxK) {
                maxIndex = j;
            }
            result += max(min(minIndex, maxIndex) - i + 1, 0);
        }
        return result;
    }
};