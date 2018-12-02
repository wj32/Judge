class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> v(nums.size());
        pair<int, int> globalMaximum = {-1, 0};
        for (int i = 0; i < nums.size(); i++) {
            const int end = upper_bound(nums.begin(), nums.begin() + i, nums[i] / 2) - nums.begin();
            pair<int, int> maximum = {-1, 0};
            for (int j = 0; j < end; j++) {
                if (((nums[i] % nums[j]) == 0) && (maximum.second < v[j].second)) {
                    maximum = {j, v[j].second};
                }
            }
            maximum.second++;
            v[i] = maximum;
            if (globalMaximum.second < maximum.second) {
                globalMaximum = {i, maximum.second};
            }
        }

        vector<int> r(globalMaximum.second);
        int index = globalMaximum.first;
        for (int i = r.size() - 1; i >= 0; i--) {
            r[i] = nums[index];
            index = v[index].first;
        }
        return r;
    }
};
