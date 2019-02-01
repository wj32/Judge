class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const auto isMagicSquare = [&](int i, int j) {
            const auto sumRow0 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
            const auto sumRow1 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
            const auto sumRow2 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
            if ((sumRow0 != sumRow1) || (sumRow1 != sumRow2)) {
                return false;
            }
            if ((grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != sumRow0) ||
                (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] != sumRow0)) {
                return false;
            }
            if ((grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sumRow0) ||
                (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sumRow0)) {
                return false;
            }
            set<int> s;
            for (int di = 0; di < 3; di++) {
                for (int dj = 0; dj < 3; dj++) {
                    s.insert(grid[i + di][j + dj]);
                }
            }
            if ((s.size() != 9) || (*s.begin() != 1) || (*prev(s.end()) != 9)) {
                return false;
            }
            return true;
        };

        if ((grid.size() < 3) || (grid[0].size() < 3)) {
            return 0;
        }

        int count = 0;
        for (int i = 0; i < grid.size() - 2; i++) {
            for (int j = 0; j < grid[0].size() - 2; j++) {
                if (isMagicSquare(i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
