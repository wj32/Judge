class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r(nums1.size(), 0);
        for (const auto x : nums2) {
            int b = 0;
            int c = 0;
            for (size_t i = 0; i < nums1.size(); ++i) {
                if (nums1[i] == x) {
                    c = max(c, b + 1);
                }
                b = max(b, r[i]);
                r[i] = max(r[i], c);
            }
        }
        return r.back();
    }
};