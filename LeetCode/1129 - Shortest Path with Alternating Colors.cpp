class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        array<vector<vector<int>>, 2> edges;
        for (int color = 0; color < 2; ++color) {
            edges[color] = vector<vector<int>>(n);
            for (const auto& e : (color == 0 ? redEdges : blueEdges)) {
                edges[color][e[0]].push_back(e[1]);
            }
        }
        array<vector<int>, 2> costs;
        queue<tuple<int, int, int>> q;
        for (int color = 0; color < 2; ++color) {
            costs[color] = vector<int>(n, numeric_limits<int>::max());
            costs[color][0] = 0;
            for (const auto k : edges[color][0]) {
                q.emplace(k, color, 1);
            }
        }
        while (!q.empty()) {
            const auto [node, color, cost] = q.front();
            q.pop();
            auto& bestCost = costs[color][node];
            if (cost >= bestCost) {
                continue;
            }
            bestCost = cost;
            for (const auto k : edges[!color][node]) {
                q.emplace(k, !color, cost + 1);
            }
        }
        vector<int> result(n);
        for (int k = 0; k < n; ++k) {
            const auto cost = min(costs[0][k], costs[1][k]);
            result[k] = cost != numeric_limits<int>::max() ? cost : -1;
        }
        return result;
    }
};