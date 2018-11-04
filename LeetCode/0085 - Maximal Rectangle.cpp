class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        const auto m = matrix.size();
        const auto n = matrix[0].size();

        int maxArea = 0;
        vector<int> heights(n, 0);
        vector<pair<int, int>> s;
        s.reserve(n);

        for (int i = 0; i < m; i++) {
            s.clear();
            s.push_back({-1, 0});

            for (int j = 0; j <= n; j++) {
                const auto h = [&] {
                    if (j < n) {
                        heights[j] = (matrix[i][j] == '0') ? 0 : (heights[j] + 1);
                        return heights[j];
                    }
                    else {
                        return 0;
                    }
                }();

                while (s.back().second > h) {
                    const auto g = s.back().second;
                    s.pop_back();
                    maxArea = max(maxArea, (j - s.back().first - 1) * g);
                }

                if (s.back().second == h) {
                    s.back().first = j;
                }
                else {
                    s.push_back({j, h});
                }
            }
        }

        return maxArea;
    }
};
