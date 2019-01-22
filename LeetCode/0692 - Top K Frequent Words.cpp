class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (const auto& word : words) {
            m[word]++;
        }

        const auto cmp = [&](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);

        for (const auto& p : m) {
            q.push(p);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<string> r(k);
        for (int i = k - 1; i >= 0; i--) {
            r[i] = q.top().first;
            q.pop();
        }
        return r;
    }
};
