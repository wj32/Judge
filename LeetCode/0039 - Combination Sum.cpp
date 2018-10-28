class Solution {
public:
    vector<vector<int>> combinations(int k, const vector<int>& candidates, int target) {
        vector<vector<int>> r;

        if (target == 0) {
            r.push_back({});
        }
        else if ((k < candidates.size()) && (candidates[k] <= target)) {
            for (auto v : combinations(k, candidates, target - candidates[k])) {
                v.push_back(candidates[k]);
                r.push_back(v);
            }

            for (auto v : combinations(k + 1, candidates, target)) {
                r.push_back(v);
            }
        }

        return r;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinations(0, candidates, target);
    }
};
