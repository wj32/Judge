class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int maxArea = 0;

        s.push({-1, 0});

        for (int i = 0; i <= heights.size(); i++) {
            const auto h = (i < heights.size()) ? heights[i] : 0;

            while (s.top().second > h) {
                const auto g = s.top().second;
                s.pop();
                maxArea = max(maxArea, (i - s.top().first - 1) * g);
            }

            if (s.top().second == h) {
                s.top().first = i;
            }
            else {
                s.push({i, h});
            }
        }

        return maxArea;
    }
};
