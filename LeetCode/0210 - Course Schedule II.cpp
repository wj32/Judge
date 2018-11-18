class Solution {
public:
    struct Node {
        int course;
        bool visiting;
        bool visited;
        vector<Node*> prerequisites;
    };

    bool visit(Node* node, vector<int>* order) {
        if (node->visited) {
            return false;
        }
        if (node->visiting) {
            return true;
        }

        node->visiting = true;

        for (const auto prerequisite : node->prerequisites) {
            if (visit(prerequisite, order)) {
                return true;
            }
        }

        node->visiting = false;
        node->visited = true;

        order->push_back(node->course);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Node*> nodes(numCourses);

        for (int course = 0; course < numCourses; course++) {
            nodes[course] = new Node{course, false, false, {}};
        }

        for (const auto& p : prerequisites) {
            nodes[p.first]->prerequisites.push_back(nodes[p.second]);
        }

        vector<int> order;
        order.reserve(numCourses);

        for (int course = 0; course < numCourses; course++) {
            if (visit(nodes[course], &order)) {
                return {};
            }
        }

        return order;
    }
};
