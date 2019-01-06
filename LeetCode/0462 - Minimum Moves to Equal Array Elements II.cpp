class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int mid = nums.size() / 2;
        const int median = nums[mid];
        return
            ((median * mid) - accumulate(nums.begin(), nums.begin() + mid, 0)) +
            (accumulate(nums.begin() + mid + 1, nums.end(), 0) - (median * (nums.size() - mid - 1)));
    }
};
