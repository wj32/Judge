class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        unordered_map<int, int> r;
        int minArea = numeric_limits<int>::max();
        for (int m = 0; m < points.size(); ) {
            int n = m;
            while (n < points.size() && points[n][0] == points[m][0]) {
                ++n;
            }
            for (int i = m; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (const auto [it, inserted] = r.try_emplace((points[i][1] << 16) + points[j][1], points[m][0]); !inserted) {
                        minArea = min(minArea, (points[j][1] - points[i][1]) * (points[m][0] - it->second));
                        it->second = points[m][0];
                    }
                }
            }
            m = n;
        }
        return minArea < numeric_limits<int>::max() ? minArea : 0;
    }
};