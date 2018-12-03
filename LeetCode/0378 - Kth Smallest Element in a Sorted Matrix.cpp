class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const auto n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            const int mid = low + (high - low + 1) / 2;
            int count = 0;
            int right = n;
            for (int i = 0; i < n; i++) {
                right = lower_bound(matrix[i].begin(), matrix[i].begin() + right, mid) - matrix[i].begin();
                if (right == 0) {
                    break;
                }
                count += right;
            }
            if (count < k) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};
