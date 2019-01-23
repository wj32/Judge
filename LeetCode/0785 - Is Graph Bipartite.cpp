class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        struct Link {
            int id;
            int parity;
        };

        vector<Link> parent(graph.size());
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = {i, 0};
        }

        const auto findRoot = [&](int rootId) -> Link {
            int parity = 0;
            while (rootId != parent[rootId].id) {
                const auto link = parent[rootId];
                parent[rootId] = {parent[link.id].id, parent[link.id].parity ^ link.parity};
                rootId = link.id;
                parity ^= link.parity;
            }
            return {rootId, parity};
        };

        for (int i = 0; i < graph.size(); i++) {
            const auto root1 = findRoot(i);
            for (const auto j : graph[i]) {
                const auto root2 = findRoot(j);
                if (root1.id == root2.id) {
                    if (root1.parity == root2.parity) {
                        return false;
                    }
                }
                else {
                    parent[root2.id] = {root1.id, root1.parity ^ root2.parity ^ 1};
                }
            }
        }

        return true;
    }
};
