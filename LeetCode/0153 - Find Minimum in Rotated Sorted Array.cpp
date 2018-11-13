class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (true) {
            assert(low <= high);
            if (nums[low] <= nums[high]) {
                return nums[low];
            }
            else {
                const int mid = low + (high - low) / 2;
                if (nums[low] <= nums[mid]) {
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            }
        }
    }
};
