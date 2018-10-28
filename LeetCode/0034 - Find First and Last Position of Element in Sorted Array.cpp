class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = -1;
        {
            int low = 0;
            int high = nums.size() - 1;

            while (low <= high) {
                const int mid = low + (high - low) / 2;
                if (target == nums[mid]) {
                    high = mid;

                    if (high == low) {
                        lb = high;
                        break;
                    }
                }
                else if (target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }

        int ub = -1;
        {
            int low = 0;
            int high = nums.size() - 1;

            while (low <= high) {
                const int mid = low + (high - low + 1) / 2;
                if (target == nums[mid]) {
                    low = mid;

                    if (low == high) {
                        ub = low;
                        break;
                    }
                }
                else if (target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }

        return {lb, ub};
    }
};
