class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (const int x : nums1) {
            const auto it = m.find(x);
            if (it != m.end()) {
                it->second++;
            }
            else {
                m.insert({x, 1});
            }
        }
        size_t dst = 0;
        for (const int x : nums2) {
            const auto it = m.find(x);
            if (it != m.end()) {
                it->second--;
                if (it->second == 0) {
                    m.erase(it);
                }
                nums2[dst] = x;
                dst++;
            }
        }
        nums2.erase(nums2.begin() + dst, nums2.end());
        return nums2;
    }
};
