class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        long long end = numeric_limits<long long>::min();
        int count = 0;
        for (const auto& p : points) {
            if (p.first <= end) {
                end = min(end, static_cast<long long>(p.second));
            }
            else {
                count++;
                end = p.second;
            }
        }
        return count;
    }
};
