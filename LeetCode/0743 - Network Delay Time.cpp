class Solution {
public:
    struct Node {
        vector<pair<int, int>> edges;
    };

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<Node> nodes(N, Node{});
        for (const auto& edge : times) {
            nodes[edge[0] - 1].edges.push_back({edge[1] - 1, edge[2]});
        }

        vector<bool> visited(N, false);
        int visitedCount = 0;

        const auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        q.push({K - 1, 0});

        int maxDistance = 0;

        while (!q.empty()) {
            const auto i = q.top().first;
            const auto distance = q.top().second;
            q.pop();

            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            visitedCount++;
            maxDistance = max(maxDistance, distance);

            for (const auto& edge : nodes[i].edges) {
                if (!visited[edge.first]) {
                    q.push({edge.first, distance + edge.second});
                }
            }
        }

        if (visitedCount < N) {
            return -1;
        }

        return maxDistance;
    }
};
