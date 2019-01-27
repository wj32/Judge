class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        const auto countMaxDistance = [&](int maxDistance) {
            int count = 0;
            int right = 0;
            for (int left = 0; left < nums.size(); left++) {
                while ((right < nums.size()) && (nums[right] - nums[left] <= maxDistance)) {
                    right++;
                }
                count += right - left - 1;
            }
            return count;
        };

        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high) {
            const int mid = low + (high - low) / 2;
            const int count = countMaxDistance(mid);

            if (k <= count) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
