class Solution {
public:
    long long recurse(int n, vector<vector<long long>>& r, int m, int start) {
        if (r[m][start] == -1) {
            r[m][start] = [&] {
                if (start + m >= n) {
                    return numeric_limits<long long>::max();
                }
                const auto& sums = r[0];
                int low = start;
                int high = n - m;
                while (low < high) {
                    const auto mid = low + (high - low + 1) / 2;
                    const auto leftSum = sums[start] - sums[mid];
                    const auto rightMinMax = recurse(n, r, m - 1, mid);
                    if (leftSum <= rightMinMax) {
                        low = mid;
                    }
                    else {
                        high = mid - 1;
                    }
                }
                const auto max1 = max(sums[start] - sums[low], recurse(n, r, m - 1, low));
                const auto max2 = max(sums[start] - sums[low + 1], recurse(n, r, m - 1, low + 1));
                return min(max1, max2);
            }();
        }
        return r[m][start];
    }

    int splitArray(vector<int>& nums, int m) {
        vector<vector<long long>> r(m, vector<long long>(nums.size() + 1, -1));
        r[0][nums.size()] = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            r[0][i] = r[0][i + 1] + nums[i];
        }
        return static_cast<int>(recurse(nums.size(), r, m - 1, 0));
    }
};
