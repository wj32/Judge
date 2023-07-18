class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long> r(questions.size());
        for (int i = questions.size() - 1; i >= 0; --i) {
            const auto j = i + questions[i][1] + 1;
            const auto solve = j < r.size() ? r[j] : 0;
            const auto skip = i + 1 < r.size() ? r[i + 1] : 0;
            r[i] = max(questions[i][0] + solve, skip);
        }
        return r[0];
    }
};