class Solution {
public:
    struct Node {
        string name;
        vector<pair<Node*, double>> edges;
        bool visiting;
    };

    pair<bool, double> search(const string& target, Node* node, double acc) {
        if (node->name == target) {
            return {true, acc};
        }

        pair<bool, double> result = {false, -1.0};

        node->visiting = true;

        for (const auto& p : node->edges) {
            if (!p.first->visiting) {
                const auto innerResult = search(target, p.first, acc * p.second);
                if (innerResult.first) {
                    result = innerResult;
                    break;
                }
            }
        }

        node->visiting = false;

        return result;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> m;

        const auto getNode = [&](const string& name) {
            const auto it = m.find(name);
            if (it != m.end()) {
                return it->second;
            }
            else {
                const auto node = new Node{name, {}};
                m.insert({name, node});
                return node;
            }
        };

        for (int i = 0; i < equations.size(); i++) {
            const auto node1 = getNode(equations[i].first);
            const auto node2 = getNode(equations[i].second);
            node1->edges.push_back({node2, values[i]});
            node2->edges.push_back({node1, 1.0 / values[i]});
        }

        vector<double> answers(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            const auto it = m.find(queries[i].first);
            if (it != m.end()) {
                answers[i] = search(queries[i].second, it->second, 1.0).second;
            }
            else {
                answers[i] = -1.0;
            }
        }
        return answers;
    }
};
