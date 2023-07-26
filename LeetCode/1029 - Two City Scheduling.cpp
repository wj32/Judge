class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        nth_element(costs.begin(), costs.begin() + costs.size() / 2, costs.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] - lhs[1] < rhs[0] - rhs[1];
        });
        int result = 0;
        for (size_t i = 0; i < costs.size() / 2; ++i) {
            result += costs[i][0];
        }
        for (size_t i = costs.size() / 2; i < costs.size(); ++i) {
            result += costs[i][1];
        }
        return result;
    }
};