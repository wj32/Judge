class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }

        const auto m = matrix.size();
        const auto n = matrix[0].size();
        const auto access = [&](size_t i) {
            return matrix[i / n][i % n];
        };

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;
            const auto x = access(mid);

            if (x == target) {
                return true;
            }
            else if (x < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false;
    }
};
