class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int prime = 1000000007;
        if (n == 1) {
            return 1;
        }
        unordered_map<int, vector<pair<int, int>>> edges;
        for (const auto& road : roads) {
            edges[road[0]].emplace_back(road[1], road[2]);
            edges[road[1]].emplace_back(road[0], road[2]);
        }
        vector<long> dist(n, numeric_limits<long>::max());
        vector<int> ways(n);
        struct Entry {
            int to;
            int from;
            long dist;

            bool operator<(const Entry& other) const {
                return dist > other.dist;
            }
        };
        priority_queue<Entry> q;
        q.push(Entry{0, 0, 0});
        ways[0] = 1;
        while (true) {
            const auto e = q.top();
            q.pop();
            if (e.dist < dist[e.to]) {
                dist[e.to] = e.dist;
                ways[e.to] = ways[e.from];
                if (const auto it = edges.find(e.to); it != edges.end()) {
                    for (const auto& p : it->second) {
                        q.push(Entry{p.first, e.to, e.dist + p.second});
                    }
                }
            } else if (e.dist == dist[e.to]) {
                ways[e.to] = (ways[e.to] + ways[e.from]) % prime;
            } else {
                if (e.dist > dist.back()) {
                    return ways.back();
                }
            }
        }
    }
};