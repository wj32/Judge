class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;

        const auto medianOf3 = [&](int i, int j, int k) {
            auto x = nums[i];
            auto y = nums[j];
            auto z = nums[k];
            if (x > y) {
                x = -x;
                y = -y;
                z = -z;
            }
            if (x > z) {
                return i;
            }
            else if (y < z) {
                return j;
            }
            else {
                return k;
            }
        };

        const auto partition = [&](int start, int end) {
            if (end - start > 10) { // Choose a better pivot for large ranges
                const auto mid = start + (end - start) / 2;
                swap(nums[medianOf3(start, mid, end)], nums[end]);
            }

            const auto pivot = nums[end];
            int dst = start;
            for (int i = start; i <= end; i++) {
                if (nums[i] <= pivot) {
                    swap(nums[dst], nums[i]);
                    dst++;
                }
            }
            return dst - 1;
        };

        int low = 0;
        int high = nums.size() - 1;
        while (true) {
            const auto pivotIndex = partition(low, high);
            if (k < pivotIndex) {
                high = pivotIndex - 1;
            }
            else if (k > pivotIndex) {
                low = pivotIndex + 1;
            }
            else {
                return nums[pivotIndex];
            }
        }
    }
};
