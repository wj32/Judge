class Solution {
public:
    int findNthElement(vector<int>& nums1, vector<int>& nums2, int target) {
        int left1 = 0;
        int right1 = nums1.size() - 1;
        int left2 = 0;
        int right2 = nums2.size() - 1;

        int which;
        int index;

        while (true) {
            if (left2 > right2) {
                which = 1;
                index = left1 + target;
                break;
            } else if (left1 > right1) {
                which = 2;
                index = left2 + target;
                break;
            }

            const int mid1 = left1 + (right1 - left1 + 1) / 2;
            const auto pos2 = lower_bound(nums2.begin() + left2, nums2.begin() + right2 + 1, nums1[mid1]);
            const int mid2 = pos2 - nums2.begin();
            const int countOnLeft = (mid1 - left1) + (mid2 - left2);
            if (target < countOnLeft) {
                right1 = mid1 - 1;
                right2 = mid2 - 1;
            } else {
                left1 = mid1;
                left2 = mid2;
                target -= countOnLeft;

                if (left1 == right1) {
                    if (target == 0) {
                        which = 1;
                        index = left1;
                    } else {
                        which = 2;
                        index = left2 + target - 1;
                    }
                    break;
                }
            }
        }

        return ((which == 1) ? nums1 : nums2)[index];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (((nums1.size() + nums2.size()) % 2) == 0) {
            const int x = findNthElement(nums1, nums2, ((nums1.size() + nums2.size()) / 2) - 1);
            const int y = findNthElement(nums1, nums2, (nums1.size() + nums2.size()) / 2);
            return static_cast<double>(x + y) / 2;
        } else {
            return findNthElement(nums1, nums2, (nums1.size() + nums2.size()) / 2);
        }
    }
};
