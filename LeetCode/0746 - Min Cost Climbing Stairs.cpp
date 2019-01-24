class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> r(cost.size());
        r[r.size() - 1] = cost[r.size() - 1];
        r[r.size() - 2] = cost[r.size() - 2];
        for (int i = static_cast<int>(r.size()) - 3; i >= 0; i--) {
            r[i] = cost[i] + min(r[i + 1], r[i + 2]);
        }
        return min(r[0], r[1]);
    }
};
