class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const auto n = triangle.size();
        if (n == 0) {
            return 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                const int x1 = (j != 0) ? triangle[i - 1][j - 1] : numeric_limits<int>::max();
                const int x2 = (j != i) ? triangle[i - 1][j] : numeric_limits<int>::max();
                triangle[i][j] += min(x1, x2);
            }
        }

        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
