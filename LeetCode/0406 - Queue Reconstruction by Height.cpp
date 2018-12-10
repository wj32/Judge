class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [&](const auto& a, const auto& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        });
        vector<pair<int, int>> r;
        r.reserve(people.size());
        for (const auto& p : people) {
            r.insert(r.begin() + p.second, p);
        }
        return r;
    }
};
