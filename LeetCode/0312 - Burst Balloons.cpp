class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const auto n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> r(n + 1);
        for (int count = 1; count <= n; count++) {
            r[count] = vector<int>(n - count + 1);
            for (int start = 0; start < n - count + 1; start++) {
                const int end = start + count;
                const int lx = (start > 0) ? nums[start - 1] : 1;
                const int rx = (end < n) ? nums[end] : 1;
                int maximum = 0;
                for (int middle = start; middle < end; middle++) {
                    const int lr = (middle > start) ? r[middle - start][start] : 0;
                    const int rr = (middle < end - 1) ? r[end - middle - 1][middle + 1] : 0;
                    maximum = max(maximum, lr + (lx * nums[middle] * rx) + rr);
                    // cout << "[" << start << ", " << end - 1 << "] " << middle << ": " << lr << " + " << lx * nums[middle] * rx << " + " << rr << endl;
                }
                r[count][start] = maximum;
            }
        }
        return r[n][0];
    }
};
