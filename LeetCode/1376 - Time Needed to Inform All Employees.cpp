class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                subordinates[manager[i]].push_back(i);
            }
        }
        int r = 0;
        stack<pair<int, int>> s;
        s.emplace(headID, 0);
        while (!s.empty()) {
            const auto [i, cost] = s.top();
            s.pop();
            r = max(r, cost);
            for (const auto j : subordinates[i]) {
                s.emplace(j, cost + informTime[i]);
            }
        }
        return r;
    }
};