class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const auto distance = [&](const vector<int>& a, const vector<int>& b) {
            const double dx = a[0] - b[0];
            const double dy = a[1] - b[1];
            return sqrt((dx * dx) + (dy * dy));
        };

        double maxArea = 0;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                const auto a = distance(points[i], points[j]);
                for (int k = j + 1; k < points.size(); k++) {
                    const auto b = distance(points[i], points[k]);
                    const auto c = distance(points[j], points[k]);
                    const auto p = (a + b + c) / 2;
                    maxArea = max(maxArea, p * (p - a) * (p - b) * (p - c));
                }
            }
        }

        return sqrt(maxArea);
    }
};
