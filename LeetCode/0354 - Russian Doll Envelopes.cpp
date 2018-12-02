class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        const auto cmp = [&](const auto& a, const auto& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            else {
                return a.second > b.second;
            }
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> v;
        for (int i = 0; i < envelopes.size(); i++) {
            const auto it = lower_bound(v.begin(), v.end(), envelopes[i].second);
            if (it != v.end()) {
                *it = envelopes[i].second;
            }
            else {
                v.push_back(envelopes[i].second);
            }
        }
        return v.size();
    }
};
