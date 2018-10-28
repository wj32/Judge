class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;

            if (target <= nums[mid]) {
                high = mid;

                if (high == low) {
                    break;
                }
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
