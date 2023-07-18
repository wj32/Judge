class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<pair<long, int>> thresholds(spells.size());
        for (size_t i = 0; i < spells.size(); ++i) {
            thresholds[i] = pair((success + spells[i] - 1) / spells[i], i);
        }
        sort(thresholds.begin(), thresholds.end());
        vector<int> result(spells.size());
        auto it = potions.begin();
        for (const auto [threshold, i] : thresholds) {
            it = lower_bound(it, potions.end(), threshold);
            result[i] = distance(it, potions.end());
        }
        return result;
    }
};