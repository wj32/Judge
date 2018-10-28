class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;

            bool left;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = (nums[mid] <= nums[high]) && (nums[high] < target);
            } else {
                left = !((nums[low] <= nums[mid]) && (target < nums[low]));
            }

            if (left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};
