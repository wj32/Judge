/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> clonedNodes;
        queue<UndirectedGraphNode*> q;

        const auto clonedHead = new UndirectedGraphNode(head->label);
        clonedNodes.insert({head, clonedHead});
        q.push(head);

        while (!q.empty()) {
            for (const auto neighbor : q.front()->neighbors) {
                if (clonedNodes.find(neighbor) == clonedNodes.end()) {
                    clonedNodes.insert({neighbor, new UndirectedGraphNode(neighbor->label)});
                    q.push(neighbor);
                }
            }
            q.pop();
        }

        for (const auto& p : clonedNodes) {
            for (const auto neighbor : p.first->neighbors) {
                p.second->neighbors.push_back(clonedNodes.find(neighbor)->second);
            }
        }

        return clonedHead;
    }
};
