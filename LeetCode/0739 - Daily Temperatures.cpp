class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<pair<int, int>> s;
        s.reserve(T.size());
        for (int i = T.size() - 1; i >= 0; i--) {
            const int x = T[i];
            while (!s.empty() && (s.back().first <= x)) {
                s.pop_back();
            }
            T[i] = s.empty() ? 0 : (s.back().second - i);
            s.push_back({x, i});
        }
        return T;
    }
};
