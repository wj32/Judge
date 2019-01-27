class Solution {
private:
    random_device rd;
    default_random_engine gen;

    vector<pair<int, int>> ranges;
    int totalProbability = 0;

public:
    Solution(int N, vector<int> blacklist) {
        sort(blacklist.begin(), blacklist.end());
        int start = 0;
        for (const int b : blacklist) {
            if (start < b) {
                ranges.push_back({totalProbability, start});
                totalProbability += b - start;
            }
            start = b + 1;
        }
        if (start < N) {
            ranges.push_back({totalProbability, start});
            totalProbability += N - start;
        }
    }

    int pick() {
        uniform_int_distribution<> dist(0, totalProbability - 1);
        const int probability = dist(gen);
        auto it = upper_bound(ranges.begin(), ranges.end(), probability, [&](int a, const auto& b) {
            return a < b.first;
        });
        assert(it != ranges.begin());
        it = prev(it);
        return it->second + (probability - it->first);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
