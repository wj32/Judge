class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;

        for (const auto s : strs) {
            auto t = s;
            sort(t.begin(), t.end());

            const auto it = m.find(t);
            if (it != m.end()) {
                it->second.push_back(s);
            }
            else {
                m.insert({t, {s}});
            }
        }

        vector<vector<string>> r;
        for (const auto p : m) {
            r.push_back(p.second);
        }
        return r;
    }
};
