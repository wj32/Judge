class Solution {
public:
    bool search(vector<vector<int>>& grid, vector<vector<bool>>& seen, int t, int i, int j) {
        const int n = grid.size();

        if (seen[i][j] || (grid[i][j] > t)) {
            return false;
        }

        if ((i == n - 1) && (j == n - 1)) {
            return true;
        }

        seen[i][j] = true;

        bool result = false;
        if (!result && (i > 0)) {
            result = search(grid, seen, t, i - 1, j);
        }
        if (!result && (i < n - 1)) {
            result = search(grid, seen, t, i + 1, j);
        }
        if (!result && (j > 0)) {
            result = search(grid, seen, t, i, j - 1);
        }
        if (!result && (j < n - 1)) {
            result = search(grid, seen, t, i, j + 1);
        }
        return result;
    }

    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<bool>> seen(n, vector<bool>(n));
        int low = max(grid[0][0], grid[n - 1][n - 1]);
        int high = (n * n) - 1;
        while (low < high) {
            const int mid = low + (high - low) / 2;
            for (auto& v : seen) {
                fill(v.begin(), v.end(), false);
            }
            if (search(grid, seen, mid, 0, 0)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
