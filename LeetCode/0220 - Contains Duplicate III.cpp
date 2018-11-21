class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> neighborhood;
        const auto add = [&](int x) {
            const auto it = neighborhood.insert(x);
            if (it != neighborhood.begin()) {
                const auto itp = prev(it);
                if (*it <= *itp + t) {
                    return true;
                }
            }
            const auto itn = next(it);
            if (itn != neighborhood.end()) {
                if (*itn <= *it + t) {
                    return true;
                }
            }
            return false;
        };

        for (size_t i = 0; i < nums.size(); i++) {
            if (i >= k + 1) {
                const auto it = neighborhood.find(nums[i - k - 1]);
                assert(it != neighborhood.end());
                neighborhood.erase(it);
            }
            if (add(nums[i])) {
                return true;
            }
        }

        return false;
    }
};
