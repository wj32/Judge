class Solution {
public:
    struct Node {
        int degree;
        int edge;
    };

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<Node> nodes(n, Node{0, 0});
        int nodeCount = n;

        for (const auto& p : edges) {
            nodes[p.first].degree++;
            nodes[p.first].edge ^= p.second;
            nodes[p.second].degree++;
            nodes[p.second].edge ^= p.first;
        }

        vector<int> u;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            if (nodes[i].degree == 1) {
                u.push_back(i);
            }
        }

        while (nodeCount > 2) {
            for (const auto id : u) {
                const auto node = &nodes[id];
                const auto otherNode = &nodes[node->edge];
                nodeCount--;
                otherNode->degree--;
                otherNode->edge ^= id;
                if (otherNode->degree == 1) {
                    v.push_back(node->edge);
                }
            }

            swap(u, v);
            v.clear();
        }

        return u;
    }
};
