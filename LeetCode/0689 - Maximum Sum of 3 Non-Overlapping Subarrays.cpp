class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> s(n - k + 1);
        vector<int> l(n - k + 1);
        vector<int> r(n - k + 1);
        int maxIndex;

        s[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        for (int i = 1; i <= n - k; i++) {
            s[i] = s[i - 1] - nums[i - 1] + nums[i + k - 1];
        }

        maxIndex = 0;
        l[0] = maxIndex;
        for (int i = 1; i <= n - k; i++) {
            if (s[maxIndex] < s[i]) {
                maxIndex = i;
            }
            l[i] = maxIndex;
        }

        maxIndex = n - k;
        r[n - k] = maxIndex;
        for (int i = n - k - 1; i >= 0; i--) {
            if (s[maxIndex] < s[i]) {
                maxIndex = i;
            }
            r[i] = maxIndex;
        }

        auto maximum = make_tuple(s[l[0]] + s[k] + s[r[k * 2]], l[0], k, r[k * 2]);
        for (int i = k + 1; i <= n - (k * 2); i++) {
            const int sum = s[l[i - k]] + s[i] + s[r[i + k]];
            if (get<0>(maximum) < sum) {
                maximum = {sum, l[i - k], i, r[i + k]};
            }
        }
        return {get<1>(maximum), get<2>(maximum), get<3>(maximum)};
    }
};
