class Solution {
public:
    struct Node {
        int course;
        bool visiting;
        bool visited;
        vector<Node*> prerequisites;
    };

    bool visit(Node* node) {
        if (node->visited) {
            return false;
        }
        if (node->visiting) {
            return true;
        }

        node->visiting = true;

        for (const auto prerequisite : node->prerequisites) {
            if (visit(prerequisite)) {
                return true;
            }
        }

        node->visiting = false;
        node->visited = true;

        return false;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Node*> nodes(numCourses);

        for (int course = 0; course < numCourses; course++) {
            nodes[course] = new Node{course, false, false, {}};
        }

        for (const auto& p : prerequisites) {
            nodes[p.first]->prerequisites.push_back(nodes[p.second]);
        }

        for (int course = 0; course < numCourses; course++) {
            if (visit(nodes[course])) {
                return false;
            }
        }

        return true;
    }
};
