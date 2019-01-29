class Solution {
public:
    enum class State : char {
        Initial,
        Visiting,
        Cycle,
        NoCycle
    };

    State findCycle(int node, const vector<vector<int>>& graph, vector<State>& state) {
        switch (state[node]) {
            case State::Initial:
                state[node] = State::Visiting;
                for (const int outNode : graph[node]) {
                    if (findCycle(outNode, graph, state) == State::Cycle) {
                        state[node] = State::Cycle;
                        return state[node];
                    }
                }
                state[node] = State::NoCycle;
                break;

            case State::Visiting:
                state[node] = State::Cycle;
                break;

            case State::Cycle:
            case State::NoCycle:
            default:
                break;
        }

        return state[node];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<State> state(graph.size(), State::Initial);
        vector<int> noCycleNodes;
        for (int i = 0; i < graph.size(); i++) {
            if (findCycle(i, graph, state) == State::NoCycle) {
                noCycleNodes.push_back(i);
            }
        }
        return noCycleNodes;
    }
};
