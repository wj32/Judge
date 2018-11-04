class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) {
            return {{}};
        }

        const auto d = [&] {
            map<int, int> m;
            for (const int x : nums) {
                const auto it = m.find(x);
                if (it != m.end()) {
                    it->second++;
                }
                else {
                    m.insert({x, 2});
                }
            }

            vector<pair<int, int>> c;
            for (const auto& p : m) {
                c.push_back(p);
            }

            return c;
        }();

        vector<vector<int>> r;
        vector<int> c(d.size(), 0);

        while (true) {
            vector<int> v;
            v.reserve(accumulate(c.begin(), c.end(), 0));
            for (int i = 0; i < c.size(); i++) {
                for (int j = 0; j < c[i]; j++) {
                    v.push_back(d[i].first);
                }
            }
            r.push_back(move(v));

            int i = c.size() - 1;
            for (; i >= 0; i--) {
                c[i]++;
                if (c[i] != d[i].second) {
                    break;
                }
                c[i] = 0;
            }
            if (i == -1) {
                break;
            }
        }

        return r;
    }
};
