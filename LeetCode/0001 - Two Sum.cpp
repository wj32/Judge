class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numsAug(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            numsAug[i] = {nums[i], i};
        }

        sort(numsAug.begin(), numsAug.end(), [&](auto x, auto y) { return x.first < y.first; });

        int i = 0;
        int j = numsAug.size() - 1;
        while (i < j) {
            int sum = numsAug[i].first + numsAug[j].first;

            if (sum == target) {
                return {numsAug[i].second, numsAug[j].second};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        throw "failed";
    }
};
