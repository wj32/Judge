class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int count = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (j != i) {
                    const int dx = points[i].first - points[j].first;
                    const int dy = points[i].second - points[j].second;
                    m[(dx * dx) + (dy * dy)]++;
                }
            }
            for (const auto& p : m) {
                count += p.second * (p.second - 1);
            }
            m.clear();
        }
        return count;
    }
};
