class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        int count = 0;
        int product = 1;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            while ((product >= k) && (left < right)) {
                product /= nums[left];
                left++;
            }
            if (product < k) {
                count += right - left + 1;
            }
            else {
                product = 1;
                left = right + 1;
            }
        }
        return count;
    }
};
