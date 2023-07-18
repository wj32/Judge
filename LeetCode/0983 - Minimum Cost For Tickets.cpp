class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> r(days.size() + 1);
        r[0] = 0;
        for (int i = 1; i <= days.size(); ++i) {
            const auto findPriorIndex = [&](const auto offset) {
                return distance(days.begin(), upper_bound(days.begin(), days.begin() + i - 1, days[i - 1] - offset));
            };
            r[i] = min({costs[0] + r[i - 1], costs[1] + r[findPriorIndex(7)], costs[2] + r[findPriorIndex(30)]});
        }
        return r[days.size()];
    }
};