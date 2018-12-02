class Solution {
public:
    vector<vector<int>> maxSequences(vector<int>& nums, int k) {
        const auto remove = [&]() {
            int i = 0;
            while ((i < nums.size() - 1) && (nums[i] >= nums[i + 1])) {
                i++;
            }
            nums.erase(nums.begin() + i);
        };
        while (nums.size() > k) {
            remove();
        }
        vector<vector<int>> r(k + 1);
        r[k] = nums;
        for (int j = k - 1; j >= 0; j--) {
            remove();
            r[j] = nums;
        }
        return r;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // const auto xs = vector<int>{9,1,8,2,5,8,3};
        // const auto s = maxSequences(xs, xs.size());
        // for (const auto& a : s) {
        //     for (const int x : a) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        const auto l1 = min(static_cast<int>(nums1.size()), k);
        const auto l2 = min(static_cast<int>(nums2.size()), k);
        const auto m1 = maxSequences(nums1, l1);
        const auto m2 = maxSequences(nums2, l2);

        vector<int> best(k, 0);

        const auto merge = [&](const vector<int>& s1, const vector<int>& s2) {
            int i1 = 0;
            int i2 = 0;
            int k = 0;
            bool better = false;

            const auto record = [&](int x) {
                if (better || (x >= best[k])) {
                    if (x > best[k]) {
                        better = true;
                    }
                    best[k] = x;
                    k++;
                    return true;
                }
                else {
                    return false;
                }
            };

            while ((i1 < s1.size()) || (i2 < s2.size())) {
                bool take1;

                if ((i1 < s1.size()) && (i2 < s2.size()) && (s1[i1] != s2[i2])) {
                    take1 = s1[i1] > s2[i2];
                }
                else {
                    int j1 = i1;
                    int j2 = i2;
                    while ((j1 < s1.size()) && (j2 < s2.size()) && (s1[j1] == s2[j2])) {
                        j1++;
                        j2++;
                    }
                    if ((j1 < s1.size()) && (j2 < s2.size())) {
                        take1 = s1[j1] > s2[j2];
                    }
                    else {
                        take1 = (s1.size() - j1) > (s2.size() - j2);
                    }
                }

                if (take1) {
                    if (!record(s1[i1])) {
                        return;
                    }
                    i1++;
                }
                else {
                    if (!record(s2[i2])) {
                        return;
                    }
                    i2++;
                }
            }
        };

        for (int j = k - l2; j <= l1; j++) {
            // cout << "merging:" << endl;
            // for (const int x : m1[j]) {
            //     cout << x << " ";
            // }
            // cout << endl;
            // for (const int x : m2[k - j]) {
            //     cout << x << " ";
            // }
            // cout << endl;
            merge(m1[j], m2[k - j]);
        }

        return best;
    }
};
