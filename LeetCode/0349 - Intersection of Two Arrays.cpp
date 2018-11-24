class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for (const int x : nums1) {
            s.insert(x);
        }
        size_t dst = 0;
        for (const int x : nums2) {
            const auto it = s.find(x);
            if (it != s.end()) {
                s.erase(it);
                nums2[dst] = x;
                dst++;
            }
        }
        nums2.erase(nums2.begin() + dst, nums2.end());
        return nums2;
    }
};
