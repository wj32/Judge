class Solution {
private:
    vector<pair<int, vector<int>>> r;
    int totalProbability = 0;
    random_device rd;
    mt19937 gen;

public:
    Solution(vector<vector<int>> rects) : gen(rd()) {
        r.reserve(rects.size());
        for (const auto& rect : rects) {
            const int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            r.push_back({totalProbability, rect});
            totalProbability += area;
        }
    }

    vector<int> pick() {
        uniform_int_distribution<> dist(0, totalProbability - 1);
        const int cp = dist(gen);
        const auto it = upper_bound(r.begin(), r.end(), cp, [&](int a, const auto& b) { return a < b.first; });
        assert(it != r.begin());
        const auto& p = *prev(it);
        const auto offset = cp - p.first;
        const auto& rect = p.second;
        const auto width = rect[2] - rect[0] + 1;
        return {rect[0] + (offset % width), rect[1] + (offset / width)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
