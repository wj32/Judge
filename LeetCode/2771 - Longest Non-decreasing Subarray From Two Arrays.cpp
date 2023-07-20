class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r1(nums1.size());
        vector<int> r2(nums2.size());
        r1[0] = 1;
        r2[0] = 1;
        for (size_t i = 1; i < nums1.size(); ++i) {
            r1[i] = max(nums1[i - 1] <= nums1[i] ? r1[i - 1] : 0,
                        nums2[i - 1] <= nums1[i] ? r2[i - 1] : 0) + 1;
            r2[i] = max(nums1[i - 1] <= nums2[i] ? r1[i - 1] : 0,
                        nums2[i - 1] <= nums2[i] ? r2[i - 1] : 0) + 1;
        }
        return max(*max_element(r1.begin(), r1.end()),
                   *max_element(r2.begin(), r2.end()));
    }
};