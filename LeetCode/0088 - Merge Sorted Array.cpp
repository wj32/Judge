class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int dst = m + n;

        while ((m != 0) && (n != 0)) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[dst - 1] = nums1[m - 1];
                m--;
            }
            else {
                nums1[dst - 1] = nums2[n - 1];
                n--;
            }

            dst--;
        }

        while (m != 0) {
            nums1[dst - 1] = nums1[m - 1];
            m--;
            dst--;
        }

        while (n != 0) {
            nums1[dst - 1] = nums2[n - 1];
            n--;
            dst--;
        }
    }
};
