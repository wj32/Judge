class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const int x : nums) {
            const auto it = m.find(x);
            if (it != m.end()) {
                it->second++;
            }
            else {
                m.insert({x, 1});
            }
        }

        const auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (const auto& p : m) {
            q.push(p);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<int> r(k);
        for (int i = 0; i < k; i++) {
            r[i] = q.top().first;
            q.pop();
        }
        return r;
    }
};
