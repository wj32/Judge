class Solution {
public:
    struct Node {
        int index;
        vector<Node*> edges;
        int totalCount = 0;
        int totalDistance = 0;
    };

    void computeRooted(Node* node, Node* parent) {
        for (const auto otherNode : node->edges) {
            if (otherNode != parent) {
                computeRooted(otherNode, node);
                node->totalCount += otherNode->totalCount + 1;
                node->totalDistance += otherNode->totalDistance;
            }
        }
        node->totalDistance += node->totalCount;
    }

    void computeUnrooted(Node* node, Node* parent, vector<int>& totalUnrootedDistances,
                         int parentTotalCount, int parentTotalDistance) {
        totalUnrootedDistances[node->index] = parentTotalDistance + node->totalDistance;

        for (const auto otherNode : node->edges) {
            if (otherNode != parent) {
                const auto childParentTotalCount =
                    parentTotalCount + node->totalCount - otherNode->totalCount;
                const auto childParentTotalDistance =
                    parentTotalDistance +
                    node->totalDistance - (otherNode->totalDistance + otherNode->totalCount + 1) +
                    childParentTotalCount;
                computeUnrooted(otherNode, node, totalUnrootedDistances,
                                childParentTotalCount, childParentTotalDistance);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<Node> nodes(N);
        for (int i = 0; i < N; i++) {
            nodes[i].index = i;
        }
        for (const auto& edge : edges) {
            nodes[edge[0]].edges.push_back(&nodes[edge[1]]);
            nodes[edge[1]].edges.push_back(&nodes[edge[0]]);
        }

        computeRooted(&nodes[0], nullptr);

        vector<int> totalUnrootedDistances(N);

        computeUnrooted(&nodes[0], nullptr, totalUnrootedDistances, 0, 0);

        return totalUnrootedDistances;
    }
};
