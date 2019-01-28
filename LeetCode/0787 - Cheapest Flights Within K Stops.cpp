class Solution {
public:
    struct Node {
        vector<pair<int, int>> edges;
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<Node> nodes(n, Node{});
        for (const auto& flight : flights) {
            nodes[flight[0]].edges.push_back({flight[1], flight[2]});
        }

        struct Entry {
            int city;
            int cost;
            int steps;
        };
        const auto cmp = [&](const Entry& a, const Entry& b) {
            return a.cost > b.cost;
        };
        priority_queue<Entry, vector<Entry>, decltype(cmp)> q(cmp);

        q.push({src, 0, 0});

        while (!q.empty()) {
            const auto entry = q.top();
            q.pop();

            if (entry.city == dst) {
                return entry.cost;
            }

            if (entry.steps <= K) {
                for (const auto [city, cost] : nodes[entry.city].edges) {
                    q.push({city, entry.cost + cost, entry.steps + 1});
                }
            }
        }

        return -1;
    }
};
