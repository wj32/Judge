class Solution {
public:
    void recurse(const vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int node) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            paths.push_back(path);
        }
        else {
            for (const auto outNode : graph[node]) {
                recurse(graph, paths, path, outNode);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        recurse(graph, paths, path, 0);
        return paths;
    }
};
