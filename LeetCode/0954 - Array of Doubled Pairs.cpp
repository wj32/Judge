class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> m;
        for (const auto x : arr) {
            ++m[x];
        }
        const auto reduce = [&](const auto& p) {
            const auto it = m.find(p.first * 2);
            if (it == m.end() || it->second < p.second) {
                return false;
            }
            it->second -= p.second;
            if (it->second == 0) {
                m.erase(it);
            }
            return true;
        };
        // == 0
        auto it = m.lower_bound(0);
        if (it->first == 0) {
            if (it->second % 2 != 0) {
                return false;
            }
            it = m.erase(it);
        }
        // > 0
        while (it != m.end()) {
            if (!reduce(*it)) {
                return false;
            }
            it = m.erase(it);
        }
        // < 0
        while (!m.empty()) {
            if (!reduce(*prev(m.end()))) {
                return false;
            }
            m.erase(prev(m.end()));
        }
        return true;
    }
};