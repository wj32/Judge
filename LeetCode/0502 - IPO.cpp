class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> projects(Profits.size());
        for (int i = 0; i < Profits.size(); i++) {
            projects[i] = {Capital[i], Profits[i]};
        }
        sort(projects.begin(), projects.end(), [&](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        auto project = projects.begin();

        priority_queue<int> q;

        const auto populate = [&]() {
            while ((project != projects.end()) && (project->first <= W)) {
                q.push(project->second);
                project++;
            }
        };

        populate();
        while ((k != 0) && !q.empty()) {
            k--;
            W += q.top();
            q.pop();
            populate();
        }

        return W;
    }
};
