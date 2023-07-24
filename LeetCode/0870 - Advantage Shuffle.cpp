class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> v;
        v.reserve(nums2.size());
        for (int i = 0; i < nums2.size(); ++i) {
            v.emplace_back(nums2[i], i);
        }
        sort(v.begin(), v.end());
        sort(nums1.begin(), nums1.end());
        vector<int> r(nums2.size());
        auto left = v.begin();
        auto right = v.rbegin();
        for (const auto x : nums1) {
            if (x > left->first) {
                r[left->second] = x;
                ++left;
            } else {
                r[right->second] = x;
                ++right;
            }
        }
        return r;
    }
};