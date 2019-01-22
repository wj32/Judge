class Solution {
public:
    struct Node {
        int degree;
        int edge;
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<Node> nodes(edges.size(), Node{0, 0});

        for (const auto& edge : edges) {
            nodes[edge[0] - 1].degree++;
            nodes[edge[0] - 1].edge ^= edge[1] - 1;
            nodes[edge[1] - 1].degree++;
            nodes[edge[1] - 1].edge ^= edge[0] - 1;
        }

        vector<int> u;
        vector<int> v;

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].degree == 1) {
                u.push_back(i);
            }
        }

        while (!u.empty()) {
            for (const auto id : u) {
                const auto node = &nodes[id];
                const auto otherNode = &nodes[node->edge];
                node->degree--;
                otherNode->degree--;
                otherNode->edge ^= id;
                if (otherNode->degree == 1) {
                    v.push_back(node->edge);
                }
            }

            u.clear();
            swap(u, v);
        }

        for (int i = edges.size() - 1; i >= 0; i--) {
            const auto& edge = edges[i];
            if ((nodes[edge[0] - 1].degree != 0) && (nodes[edge[1] - 1].degree != 0)) {
                return edges[i];
            }
        }
        return {};
    }
};
