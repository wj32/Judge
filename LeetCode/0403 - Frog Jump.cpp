class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<set<int>> v(stones.size());
        v[0].insert(0);
        for (int i = 0; i < stones.size() - 1; i++) {
            auto it = stones.begin() + i + 1;
            for (const int d : v[i]) {
                if ((it != stones.end()) && (*it < stones[i] + d - 1)) {
                    it = lower_bound(it, stones.end(), stones[i] + d - 1);
                }
                auto it2 = it;
                while ((it2 != stones.end()) && (*it2 <= stones[i] + d + 1)) {
                    v[it2 - stones.begin()].insert(*it2 - stones[i]);
                    it2++;
                }
            }
            v[i].clear();
        }
        return !v.back().empty();
    }
};
