class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int low = 0;
        int high = nums.size() - 1;

        if (nums[low] > nums[low + 1]) {
            return low;
        }
        if (nums[high - 1] < nums[high]) {
            return high;
        }

        while (true) {
            // Invariant: There are at least 3 elements in [low, high].
            // Invariant: low and high are not peaks.
            assert(nums.size() >= 3);
            const int mid = low + (high - low) / 2;

            if (nums[mid - 1] > nums[mid]) {
                high = mid;
            }
            else if (nums[mid] < nums[mid + 1]) {
                low = mid;
            }
            else {
                return mid;
            }
        }
    }
};
