class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int, int>> forward;
        vector<pair<int, int>> backward;

        forward.push_back({0, height[0]});
        for (int i = 1; i < height.size(); i++) {
            if (height[i] > forward.back().second) {
                forward.push_back({i, height[i]});
            }
        }

        backward.push_back({height.size() - 1, height[height.size() - 1]});
        for (int i = height.size() - 2; i >= 0; i--) {
            if (height[i] > backward.back().second) {
                backward.push_back({i, height[i]});
            }
        }

        int maximumArea = 0;

        const auto traverse = [&](const vector<pair<int, int>>& u, const vector<pair<int, int>>& v) {
            int i = 0;
            for (int j = 0; j < u.size(); j++) {
                while ((i < v.size()) && (v[i].second < u[j].second)) {
                    i++;
                }
                if (i == v.size()) {
                    break;
                }
                const int area = u[j].second * abs(v[i].first - u[j].first);
                if (maximumArea < area) {
                    maximumArea = area;
                }
            }
        };

        traverse(forward, backward);
        traverse(backward, forward);

        return maximumArea;
    }
};
