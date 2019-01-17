
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const int n = M.size();
        vector<int> parents(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        const auto findRoot = [&](int i) {
            int root = i;
            while (root != parents[root]) {
                const int parent = parents[root];
                parents[root] = parents[parent];
                root = parent;
            }
            return root;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] != 0) {
                    const auto root1 = findRoot(i);
                    const auto root2 = findRoot(j);
                    parents[root2] = root1;
                }
            }
        }

        vector<bool> roots(n, false);
        for (int i = 0; i < n; i++) {
            roots[findRoot(i)] = true;
        }

        int count = 0;
        for (const auto b : roots) {
            if (b) {
                count++;
            }
        }
        return count;
    }
};
