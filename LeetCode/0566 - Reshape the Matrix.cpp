class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) {
            return {};
        }
        const int m = nums.size();
        const int n = nums[0].size();
        if (r * c != m * n) {
            return nums;
        }
        vector<vector<int>> a(r, vector<int>(c));
        int k = 0;
        int l = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[k][l] = nums[i][j];
                l++;
                if (l == c) {
                    l = 0;
                    k++;
                }
            }
        }
        return a;
    }
};
