class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const auto n = nums.size();

        vector<pair<int, int>> v(n);
        for (size_t i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());

        for (size_t i = 1; i < v.size(); i++) {
            if ((v[i].first == v[i - 1].first) &&
                (v[i].second - v[i - 1].second <= k)) {
                return true;
            }
        }

        return false;
    }
};
