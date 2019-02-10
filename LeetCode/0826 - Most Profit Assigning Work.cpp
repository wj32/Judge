class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs(difficulty.size());
        for (int i = 0; i < difficulty.size(); i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [&](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        sort(worker.begin(), worker.end());

        int totalProfit = 0;
        int maxJobProfit = 0;
        int jobIndex = 0;
        for (const auto ability : worker) {
            while ((jobIndex < jobs.size()) && (jobs[jobIndex].first <= ability)) {
                maxJobProfit = max(maxJobProfit, jobs[jobIndex].second);
                jobIndex++;
            }
            totalProfit += maxJobProfit;
        }

        return totalProfit;
    }
};
