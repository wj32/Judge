class Solution {
public:
    void combinations(vector<vector<int>>* results, vector<int>* result, int k, const vector<int>& candidates, int target) {
        if (target == 0) {
            results->push_back(*result);
        }

        for (int i = k; i < candidates.size(); ) {
            if (candidates[i] > target) {
                break;
            }

            int j = i + 1;

            while ((j < candidates.size()) && (candidates[j] == candidates[i])) {
                j++;
            }

            const int count = j - i;

            int c = 1;
            for (; c <= count; c++) {
                if (candidates[i] * c > target) {
                    break;
                }

                result->push_back(candidates[i]);
                combinations(results, result, j, candidates, target - candidates[i] * c);
            }

            while (--c != 0) {
                result->pop_back();
            }

            i = j;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> result;
        combinations(&results, &result, 0, candidates, target);
        return results;
    }
};
