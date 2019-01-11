class Solution {
public:
    int recurse(vector<int>& nums, int start, int end) {
        if (end - start <= 1) {
            return 0;
        }

        const int mid = start + (end - start) / 2;
        int result = 0;

        result += recurse(nums, start, mid);
        result += recurse(nums, mid, end);

        int leftIndex = start;
        int rightIndex = mid;

        while ((leftIndex < mid) && (rightIndex < end)) {
            if (nums[leftIndex] > static_cast<long long>(nums[rightIndex]) * 2) {
                rightIndex++;
            }
            else {
                result += rightIndex - mid;
                leftIndex++;
            }
        }

        result += (mid - leftIndex) * (rightIndex - mid);

        inplace_merge(nums.begin() + start, nums.begin() + mid, nums.begin() + end);

        return result;
    }

    int reversePairs(vector<int>& nums) {
        return recurse(nums, 0, nums.size());
    }
};
