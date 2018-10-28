class Solution {
public:
    int trap(vector<int>& height) {
        int a = 0;
        stack<tuple<int, int, int>> s;

        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && (get<1>(s.top()) < height[i])) {
                const int t = min(height[i], get<2>(s.top()));
                a += (i - get<0>(s.top()) - 1) * (t - get<1>(s.top()));
                if (t < get<2>(s.top())) {
                    get<1>(s.top()) = t;
                    break;
                } else {
                    s.pop();
                }
            }
            s.push({i, 0, height[i]});
        }

        return a;
    }
};
